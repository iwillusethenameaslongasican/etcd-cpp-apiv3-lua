#ifndef __ASYNC_LEASEGRANTACTION_HPP__
#define __ASYNC_LEASEGRANTACTION_HPP__

#include <grpc++/grpc++.h>
#include "proto/rpc.grpc.pb.h"
#include "v3/include/Action.hpp"
#include "v3/include/AsyncLeaseGrantResponse.hpp"
#include "etcd/Response.hpp"

#include <unordered_map>
#include <string>

using grpc::ClientAsyncResponseReader;
using etcdserverpb::LeaseGrantResponse;
using string_map = std::unordered_map<std::string, std::string>;

namespace etcdv3
{
  class AsyncLeaseGrantAction : public etcdv3::Action
  {
    public:
      AsyncLeaseGrantAction(etcdv3::ActionParameters param, CompletionQueue* cq, unsigned long token);
      etcd::Response ParseResponse();
    private:
      LeaseGrantResponse reply;
      std::unique_ptr<ClientAsyncResponseReader<LeaseGrantResponse>> response_reader;
  };
}

#endif
