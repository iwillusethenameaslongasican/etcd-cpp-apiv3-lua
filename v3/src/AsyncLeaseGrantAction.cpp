#include "v3/include/AsyncLeaseGrantAction.hpp"
#include "v3/include/action_constants.hpp"
#include "v3/include/Transaction.hpp"

using etcdserverpb::LeaseGrantRequest;

etcdv3::AsyncLeaseGrantAction::AsyncLeaseGrantAction(etcdv3::ActionParameters param, CompletionQueue* cq, unsigned long token)
  : etcdv3::Action(param)
{
  etcdv3::Transaction transaction;
  transaction.setup_lease_grant_operation(parameters.ttl);

  response_reader = parameters.lease_stub->AsyncLeaseGrant(&context, transaction.leasegrant_request, cq);
  response_reader->Finish(&reply, &status, (void*)token);
  
}


etcd::Response etcdv3::AsyncLeaseGrantAction::ParseResponse()
{
  AsyncLeaseGrantResponse lease_resp;
  if(!status.ok())
  {
    lease_resp.set_error_code(status.error_code());
    lease_resp.set_error_message(status.error_message());
  }
  else
  { 
    lease_resp.ParseResponse(reply);
    lease_resp.set_action(etcdv3::CREATE_ACTION);
  }
  etcd::Response resp = etcd::Response(lease_resp);          
  return resp;
}
