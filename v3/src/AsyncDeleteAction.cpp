#include "v3/include/AsyncDeleteAction.hpp"
#include "v3/include/action_constants.hpp"

using etcdserverpb::DeleteRangeRequest;

etcdv3::AsyncDeleteAction::AsyncDeleteAction(ActionParameters param, CompletionQueue* cq, unsigned long token)
  : etcdv3::Action(param) 
{
  DeleteRangeRequest del_request;
  del_request.set_key(parameters.key);
  del_request.set_prev_kv(true);
  std::string range_end(parameters.key); 
  if(parameters.withPrefix)
  {
    int ascii = (int)range_end[range_end.length()-1];
    range_end.back() = ascii+1;
    del_request.set_range_end(range_end);
  }

  response_reader = parameters.kv_stub->AsyncDeleteRange(&context, del_request, cq);
  response_reader->Finish(&reply, &status, (void*)token);
}

etcd::Response etcdv3::AsyncDeleteAction::ParseResponse()
{
  AsyncDeleteRangeResponse del_resp;
  
  if(!status.ok())
  {
    del_resp.set_error_code(status.error_code());
    del_resp.set_error_message(status.error_message());
  }
  else
  { 
    del_resp.ParseResponse(parameters.key, parameters.withPrefix, reply); 
  }
    
  etcd::Response resp = etcd::Response(del_resp);          
  return resp;
}
