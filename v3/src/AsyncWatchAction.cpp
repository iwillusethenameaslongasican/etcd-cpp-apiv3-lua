#include "v3/include/AsyncWatchAction.hpp"
#include "v3/include/action_constants.hpp"


using etcdserverpb::RangeRequest;
using etcdserverpb::RangeResponse;
using etcdserverpb::WatchCreateRequest;

etcdv3::AsyncWatchAction::AsyncWatchAction(etcdv3::ActionParameters param, CompletionQueue* watch_cq, unsigned long token)
  : etcdv3::Action(param) 
{
  isCancelled = false;
  m_token = token;
  stream = parameters.watch_stub->AsyncWatch(&context,watch_cq,(void*)"create");

  void* got_tag;
  bool ok = false;
  watch_cq->Next(&got_tag, &ok);
  if (ok && !strcmp((const char*)got_tag, "create")) 
  {
    WatchCreateRequest watch_create_req;
    watch_create_req.set_key(parameters.key);
    watch_create_req.set_prev_kv(true);
    watch_create_req.set_start_revision(parameters.revision);

    if(parameters.withPrefix)
    {
      std::string range_end(parameters.key); 
      int ascii = (int)range_end[range_end.length()-1];
      range_end.back() = ascii+1;
      watch_create_req.set_range_end(range_end);
    }

    watch_req.mutable_create_request()->CopyFrom(watch_create_req);
    stream->Write(watch_req, (void*)"write");
  }
  stream->Read(&reply, (void*)token);
}



void etcdv3::AsyncWatchAction::CancelWatch()
{
  if(isCancelled == false)
  {
    stream->WritesDone((void*)"writes done");
  }
}

int etcdv3::AsyncWatchAction::events_size()
{
  return reply.events_size();
}

void etcdv3::AsyncWatchAction::read()
{
  stream->Read(&reply, (void*)m_token);
}

etcd::Response etcdv3::AsyncWatchAction::ParseResponse()
{

  AsyncWatchResponse watch_resp;
  if(!status.ok())
  {
    watch_resp.set_error_code(status.error_code());
    watch_resp.set_error_message(status.error_message());
  }
  else
  { 
    watch_resp.ParseResponse(reply);
  }
  etcd::Response resp = etcd::Response(watch_resp);          
  return resp;
}
