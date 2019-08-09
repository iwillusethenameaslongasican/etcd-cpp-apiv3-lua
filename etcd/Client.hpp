#ifndef __ETCD_CLIENT_HPP__
#define __ETCD_CLIENT_HPP__

#include "etcd/Response.hpp"
#include "v3/include/Action.hpp"
#include "v3/include/AsyncTxnResponse.hpp"
#include "v3/include/Transaction.hpp"


#include <functional>
#include <string>


#include "proto/rpc.grpc.pb.h"
#include <grpc++/grpc++.h>


#include "luna.h"

using grpc::CompletionQueue;

using etcdserverpb::KV;
using etcdserverpb::Lease;
using etcdserverpb::Watch;

/**
 * Client is responsible for maintaining a connection towards an etcd server.
 * Etcd operations can be reached via the methods of the client.
 */
class Client final 
{
public:
  /**
   * Constructs an etcd client object.
   * @param etcd_url is the url of the etcd server to connect to, like
   * "http://127.0.0.1:4001"
   */
  Client(lua_State* L, std::string const &etcd_url);

  int wait(lua_State *L);

  int wait_watch(lua_State *L);

  int get(lua_State *L);

  int set(lua_State *L);

  int add(lua_State *L);

  int modify(lua_State *L);

  int modify_if_value(lua_State *L);

  int modify_if_index(lua_State *L);

  int rm(lua_State *L);

  int rm_if_value(lua_State *L);

  int rm_if_index(lua_State *L);

  int ls(lua_State *L);

  int rmdir(lua_State *L);

  int watch(lua_State* L);

  int CancelWatch(lua_State* L);

  int leasegrant(lua_State *L);

private:
  std::function<etcd::Response()> get_callback(int token) {
    auto it = m_callbacks.find(token);
    if (it != m_callbacks.end()) {
      return it->second;
    }
    return nullptr;
  }

  int new_token() {
    while (++m_token == 0 || m_callbacks.find(m_token) != m_callbacks.end()) {
      // nothing ...
    }
    while (++m_token == 0 || m_watch_actions.find(m_token) != m_watch_actions.end()) {
      // nothing ...
    }
    return m_token;
  }

  std::shared_ptr<etcdv3::AsyncWatchAction> get_watch_action(int token) {
    auto it = m_watch_actions.find(token);
    if (it != m_watch_actions.end()) {
      return it->second;
    }
    return nullptr;
  }

  std::unique_ptr<KV::Stub> stub_;
  std::unique_ptr<Watch::Stub> watchServiceStub;
  std::unique_ptr<Lease::Stub> leaseServiceStub;

  lua_State* m_lvm = nullptr;
  int m_token = 0;
  std::unordered_map<int, std::function<etcd::Response()>> m_callbacks;
  std::unordered_map<int, std::shared_ptr<etcdv3::AsyncWatchAction>> m_watch_actions;

protected:
  CompletionQueue cq;
  etcdv3::ActionParameters parameters;

  CompletionQueue watch_cq;

public:
  DECLARE_LUA_CLASS(Client)
};

#endif
