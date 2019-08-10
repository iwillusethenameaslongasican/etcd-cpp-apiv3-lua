#include "etcd/Client.hpp"
#include "v3/include/AsyncDeleteRangeResponse.hpp"
#include "v3/include/AsyncRangeResponse.hpp"
#include "v3/include/AsyncTxnResponse.hpp"
#include "v3/include/AsyncWatchResponse.hpp"
#include "v3/include/Transaction.hpp"
#include "v3/include/action_constants.hpp"
#include <iostream>
#include <memory>

#include "v3/include/AsyncCompareAndDeleteAction.hpp"
#include "v3/include/AsyncCompareAndSwapAction.hpp"
#include "v3/include/AsyncDeleteAction.hpp"
#include "v3/include/AsyncGetAction.hpp"
#include "v3/include/AsyncLeaseGrantAction.hpp"
#include "v3/include/AsyncSetAction.hpp"
#include "v3/include/AsyncUpdateAction.hpp"
#include "v3/include/AsyncWatchAction.hpp"

EXPORT_CLASS_BEGIN(Client)
EXPORT_LUA_FUNCTION(wait)
EXPORT_LUA_FUNCTION(wait_watch)
EXPORT_LUA_FUNCTION(get)
EXPORT_LUA_FUNCTION(set)
EXPORT_LUA_FUNCTION(add)
EXPORT_LUA_FUNCTION(modify)
EXPORT_LUA_FUNCTION(modify_if_value)
EXPORT_LUA_FUNCTION(modify_if_index)
EXPORT_LUA_FUNCTION(rm)
EXPORT_LUA_FUNCTION(rm_if_value)
EXPORT_LUA_FUNCTION(rm_if_index)
EXPORT_LUA_FUNCTION(ls)
EXPORT_LUA_FUNCTION(rmdir)
EXPORT_LUA_FUNCTION(watch)
EXPORT_LUA_FUNCTION(CancelWatch)
EXPORT_LUA_FUNCTION(leasegrant)
EXPORT_CLASS_END()

using grpc::Channel;

Client::Client(lua_State* L, std::string const &address) 
{
  std::string stripped_address;
  std::string substr("://");
  std::string::size_type i = address.find(substr);
  if (i != std::string::npos) {
    stripped_address = address.substr(i + substr.length());
  }
  std::shared_ptr<Channel> channel =
      grpc::CreateChannel(stripped_address, grpc::InsecureChannelCredentials());
  m_stub = KV::NewStub(channel);
  m_watchServiceStub = Watch::NewStub(channel);
  m_leaseServiceStub = Lease::NewStub(channel);
  m_lvm = L;
}

static void native_to_lua(lua_State* L, const etcd::Values& values)
{
    lua_newtable(L);
    for (int i = 0; i < values.size(); i ++)
    {
        etcd::Value value = values[i];
        native_to_lua(L, value.key());
        native_to_lua(L, value.value);
        lua_settable(L, -3);
    }
}

int Client::wait(lua_State *L) 
{
  void *got_tag = nullptr;
  bool ok = false;

  gpr_timespec deadline;
  deadline.tv_sec = 1; //设置1秒超时
  deadline.tv_nsec = 0;
  deadline.clock_type = GPR_TIMESPAN;

  switch (m_cq.AsyncNext<gpr_timespec>(&got_tag, &ok, deadline)) 
  {
  case CompletionQueue::TIMEOUT:
    return 0;
  case CompletionQueue::SHUTDOWN:
  {  
    std::string err;   
    lua_guard g(m_lvm);
    if(!lua_call_object_function(m_lvm, &err, this, "on_watch_response", std::tie(), (int)(unsigned long)got_tag, false, "shutdown"))
      printf("call on_watch_response error: %s\n", err.c_str());
    return 0;
  }
  case CompletionQueue::GOT_EVENT:
    std::function<etcd::Response()> callback = get_callback((int)(unsigned long)got_tag);
    if (callback != nullptr) 
    {
      etcd::Response resp = callback(); 
      std::string err;   
      lua_guard g(m_lvm);
      if(!lua_call_object_function(m_lvm, &err, this, "on_response", std::tie(), (int)(unsigned long)got_tag, resp.is_ok(),  resp.error_message(), 
                 resp.action(), resp.index(), resp.value().key(), resp.value().as_string(), resp.values()))
          printf("call on_response error: %s\n", err.c_str());
    }
    return 0;
  }
  return 0;
}

int Client::wait_watch(lua_State *L) 
{
  void* got_tag = nullptr;
  bool ok = false;  

  gpr_timespec deadline;
  deadline.tv_sec = 1; //设置1秒超时
  deadline.tv_nsec = 0;
  deadline.clock_type = GPR_TIMESPAN;  

  switch (m_watch_cq.AsyncNext<gpr_timespec>(&got_tag, &ok, deadline)) 
  {
  case CompletionQueue::TIMEOUT:
    // fprintf(stdout, "TIMEOUT\n"); 
    return 0;
  case CompletionQueue::SHUTDOWN:
    {
      std::string err;   
      lua_guard g(m_lvm);
      if(!lua_call_object_function(m_lvm, &err, this, "on_watch_response", std::tie(), (int)(unsigned long)got_tag, false,  "shutdown"))
        printf("call on_watch_response error: %s\n", err.c_str());
      return 0;
    }
  case CompletionQueue::GOT_EVENT:
    {
      // fprintf(stdout, "GOT_EVENT\n");  
      if(ok == false || got_tag == (void*)"writes done")
      {
        // fprintf(stdout, "writes done\n");
        std::shared_ptr<etcdv3::AsyncWatchAction> call = get_watch_action((int)(unsigned long)got_tag);
        if (call != nullptr)
        {  
          call->CancelWatch();
          m_watch_actions.erase((int)(unsigned long)got_tag);
        }
        std::string err;   
        lua_guard g(m_lvm);
        if(!lua_call_object_function(m_lvm, &err, this, "on_watch_response", std::tie(), (int)(unsigned long)got_tag, false,  "cancel"))
          printf("call on_watch_response error: %s\n", err.c_str());
        return 0;
      }
      std::function<etcd::Response()> callback = get_callback((int)(unsigned long)got_tag);
      std::shared_ptr<etcdv3::AsyncWatchAction> call = get_watch_action((int)(unsigned long)got_tag);
      if (callback != nullptr && call != nullptr) 
      {
        if(call->events_size())
        {
          etcd::Response resp = callback();
          std::string err;   
          lua_guard g(m_lvm);
          if(!lua_call_object_function(m_lvm, &err, this, "on_watch_response", std::tie(), (int)(unsigned long)got_tag, resp.is_ok(), resp.error_message(), 
                          resp.action(), resp.index(), resp.value().key(), resp.value().as_string(), resp.values()))
              printf("call on_watch_response error: %s\n", err.c_str());
        }
        call->read();
      }
      return 0;
    }
  }
  return 0;
}

int Client::get(lua_State *L) 
{

  const char *key = lua_tostring(L, 1);
  if (key == nullptr)
    return 0;

  etcdv3::ActionParameters params;
  params.key.assign(key);
  params.withPrefix = false;
  params.kv_stub = m_stub.get();

  int token = new_token();
  std::shared_ptr<etcdv3::AsyncGetAction> call(new etcdv3::AsyncGetAction(params, &m_cq, (unsigned long)token));
  std::function<etcd::Response()> func = std::bind(&etcdv3::AsyncGetAction::ParseResponse, call);
  m_callbacks[token] = func;
  lua_pushinteger(L, token);
  return 1;
}

int Client::set(lua_State* L) 
{

  const char *key = lua_tostring(L, 1);
  const char *value = lua_tostring(L, 2);
  int64_t leaseid = (int64_t)lua_tointeger(L, 3);
  if (key == nullptr || value == nullptr)
    return 0;

  etcdv3::ActionParameters params;
  params.key.assign(key);
  params.value.assign(value);
  params.kv_stub = m_stub.get();
  if (leaseid != 0)
    params.lease_id = leaseid;

  int token = new_token();
  std::shared_ptr<etcdv3::AsyncSetAction> call( new etcdv3::AsyncSetAction(params, &m_cq, (unsigned long)token));
  std::function<etcd::Response()> func = std::bind(&etcdv3::AsyncSetAction::ParseResponse, call);
  m_callbacks[token] = func;
  lua_pushinteger(L, token);
  return 1;
}

int Client::add(lua_State* L) 
{
  const char *key = lua_tostring(L, 1);
  const char *value = lua_tostring(L, 2);
  int64_t leaseid = (int64_t)lua_tointeger(L, 3);
  if (key == nullptr || value == nullptr)
    return 0;


  etcdv3::ActionParameters params;
  params.key.assign(key);
  params.value.assign(value);
  params.kv_stub = m_stub.get();

  if (leaseid != 0)
    params.lease_id = leaseid;

  int token = new_token();
  std::shared_ptr<etcdv3::AsyncSetAction> call(new etcdv3::AsyncSetAction(params, &m_cq, (unsigned long)token, true));
  std::function<etcd::Response()> func = std::bind(&etcdv3::AsyncSetAction::ParseResponse, call);
  m_callbacks[token] = func;
  lua_pushinteger(L, token);
  return 1;
}

int Client::modify(lua_State* L) 
{

  const char *key = lua_tostring(L, 1);
  const char *value = lua_tostring(L, 2);
  int64_t leaseid = (int64_t)lua_tointeger(L, 3);
  if (key == nullptr || value == nullptr)
    return 0;

  etcdv3::ActionParameters params;
  params.key.assign(key);
  params.value.assign(value);
  params.kv_stub = m_stub.get();

  if (leaseid != 0)
    params.lease_id = leaseid;

  int token = new_token();
  std::shared_ptr<etcdv3::AsyncUpdateAction> call(
      new etcdv3::AsyncUpdateAction(params, &m_cq, (unsigned long)token));
  std::function<etcd::Response()> func =
      std::bind(&etcdv3::AsyncUpdateAction::ParseResponse, call);
  m_callbacks[token] = func;
  lua_pushinteger(L, token);
  return 1;
}

int Client::modify_if_value(lua_State* L) 
{
  const char *key = lua_tostring(L, 1);
  const char *value = lua_tostring(L, 2);
  const char *old_value = lua_tostring(L, 3);
  int64_t leaseid = (int64_t)lua_tointeger(L, 4);
  if (key == nullptr || value == nullptr || old_value == nullptr)
    return 0;

  etcdv3::ActionParameters params;
  params.key.assign(key);
  params.value.assign(value);
  params.old_value.assign(old_value);
  params.kv_stub = m_stub.get();

  if (leaseid != 0)
    params.lease_id = leaseid;

  int token = new_token();
  std::shared_ptr<etcdv3::AsyncCompareAndSwapAction> call(new etcdv3::AsyncCompareAndSwapAction(params, etcdv3::Atomicity_Type::PREV_VALUE, &m_cq, (unsigned long)token));
  std::function<etcd::Response()> func = std::bind(&etcdv3::AsyncCompareAndSwapAction::ParseResponse, call);
  m_callbacks[token] = func;
  lua_pushinteger(L, token);
  return 1;
}

int Client::modify_if_index(lua_State* L) 
{
  
  const char *key = lua_tostring(L, 1);
  const char *value = lua_tostring(L, 2);
  int old_index = (int)lua_tointeger(L, 3);
  int64_t leaseid = (int64_t)lua_tointeger(L, 4);
  if (key == nullptr || value == nullptr)
    return 0;

  etcdv3::ActionParameters params;
  params.key.assign(key);
  params.value.assign(value);
  params.old_revision = old_index;
  params.kv_stub = m_stub.get();

  if (leaseid != 0)
    params.lease_id = leaseid;

  int token = new_token();
  std::shared_ptr<etcdv3::AsyncCompareAndSwapAction> call(new etcdv3::AsyncCompareAndSwapAction(params, etcdv3::Atomicity_Type::PREV_INDEX, &m_cq, (unsigned long)token));
  std::function<etcd::Response()> func = std::bind(&etcdv3::AsyncCompareAndSwapAction::ParseResponse, call);
  m_callbacks[token] = func;
  lua_pushinteger(L, token);
  return 1;
}

int Client::rm(lua_State* L) 
{
  const char *key = lua_tostring(L, 1);
  if (key == nullptr)
    return 0;

  etcdv3::ActionParameters params;
  params.key.assign(key);
  params.withPrefix = false;
  params.kv_stub = m_stub.get();

  int token = new_token();
  std::shared_ptr<etcdv3::AsyncDeleteAction> call(new etcdv3::AsyncDeleteAction(params, &m_cq, (unsigned long)token));
  std::function<etcd::Response()> func = std::bind(&etcdv3::AsyncDeleteAction::ParseResponse, call);
  m_callbacks[token] = func;
  lua_pushinteger(L, token);
  return 1;
}

int Client::rm_if_value(lua_State* L) 
{
  const char *key = lua_tostring(L, 1);
  const char *old_value = lua_tostring(L, 2);

  if (key == nullptr || old_value == nullptr)
    return 0;

  etcdv3::ActionParameters params;
  params.key.assign(key);
  params.old_value.assign(old_value);
  params.kv_stub = m_stub.get();

  int token = new_token();
  std::shared_ptr<etcdv3::AsyncCompareAndDeleteAction> call(new etcdv3::AsyncCompareAndDeleteAction(params, etcdv3::Atomicity_Type::PREV_VALUE, &m_cq, (unsigned long)token));
  std::function<etcd::Response()> func = std::bind(&etcdv3::AsyncCompareAndDeleteAction::ParseResponse, call);
  m_callbacks[token] = func;
  lua_pushinteger(L, token);
  return 1;
}

int Client::rm_if_index(lua_State* L) 
{
  const char *key = lua_tostring(L, 1);
  int old_index = (int)lua_tointeger(L, 2);

  if (key == nullptr)
    return 0;

  etcdv3::ActionParameters params;
  params.key.assign(key);
  params.old_revision = old_index;
  params.kv_stub = m_stub.get();

  int token = new_token();
  std::shared_ptr<etcdv3::AsyncCompareAndDeleteAction> call(new etcdv3::AsyncCompareAndDeleteAction(params, etcdv3::Atomicity_Type::PREV_INDEX, &m_cq, (unsigned long)token));
  std::function<etcd::Response()> func = std::bind(&etcdv3::AsyncCompareAndDeleteAction::ParseResponse, call);
  m_callbacks[token] = func;
  lua_pushinteger(L, token);
  return 1;
}

int Client::rmdir(lua_State* L) 
{
  const char *key = lua_tostring(L, 1);
  bool recursive = (bool)lua_toboolean(L, 2);

  if (key == nullptr)
    return 0;

  etcdv3::ActionParameters params;
  params.key.assign(key);
  params.withPrefix = recursive;
  params.kv_stub = m_stub.get();

  int token = new_token();
  std::shared_ptr<etcdv3::AsyncDeleteAction> call(new etcdv3::AsyncDeleteAction(params, &m_cq, (unsigned long)token));
  std::function<etcd::Response()> func = std::bind(&etcdv3::AsyncDeleteAction::ParseResponse, call);
  m_callbacks[token] = func;
  lua_pushinteger(L, token);
  return 1;
}

int Client::ls(lua_State* L) 
{
  const char *key = lua_tostring(L, 1);

  if (key == nullptr)
    return 0;

  etcdv3::ActionParameters params;
  params.key.assign(key);
  params.withPrefix = true;
  params.kv_stub = m_stub.get();

  int token = new_token();
  std::shared_ptr<etcdv3::AsyncGetAction> call(new etcdv3::AsyncGetAction(params, &m_cq, (unsigned long)token));
  std::function<etcd::Response()> func =std::bind(&etcdv3::AsyncGetAction::ParseResponse, call);
  m_callbacks[token] = func;
  lua_pushinteger(L, token);
  return 1;
}

int Client::watch(lua_State* L)
{
  const char *key = lua_tostring(L, 1);
  bool recursive = (bool)lua_toboolean(L, 2);
  int fromIndex = (int)lua_tointeger(L, 3);

  if (key == nullptr)
    return 0;


  etcdv3::ActionParameters params;
  params.key.assign(key);
  params.withPrefix = recursive;
  params.watch_stub = m_watchServiceStub.get();

  if(fromIndex != 0)
    params.revision = fromIndex;

  int token = new_token();
  std::shared_ptr<etcdv3::AsyncWatchAction> call(new etcdv3::AsyncWatchAction(params, &m_watch_cq, (unsigned long)token));
  m_watch_actions[token] = call;
  std::function<etcd::Response()> func =std::bind(&etcdv3::AsyncWatchAction::ParseResponse, call);
  m_callbacks[token] = func;
  lua_pushinteger(L, token);
  
  return 1;
}

int Client::CancelWatch(lua_State* L)
{
  int token = (int)lua_tointeger(L, 1);
  std::shared_ptr<etcdv3::AsyncWatchAction> call = get_watch_action(token);
  if (call != nullptr) 
    call->CancelWatch();
}

int Client::leasegrant(lua_State* L) 
{
  int ttl = (int)lua_tointeger(L, 1);

  etcdv3::ActionParameters params;
  params.ttl = ttl;
  params.lease_stub = m_leaseServiceStub.get();

  int token = new_token();
  std::shared_ptr<etcdv3::AsyncLeaseGrantAction> call(new etcdv3::AsyncLeaseGrantAction(params, &m_cq, (unsigned long)token));
  std::function<etcd::Response()> func = std::bind(&etcdv3::AsyncLeaseGrantAction::ParseResponse, call);
  m_callbacks[token] = func;
  lua_pushinteger(L, token);
  return 1;
}
