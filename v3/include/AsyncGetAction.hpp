#ifndef __ASYNC_GET_HPP__
#define __ASYNC_GET_HPP__

#include <grpc++/grpc++.h>
#include "proto/rpc.grpc.pb.h"
#include "v3/include/Action.hpp"
#include "v3/include/AsyncRangeResponse.hpp"
#include "etcd/Response.hpp"

#include <unordered_map>
#include <vector>

using grpc::ClientAsyncResponseReader;
using etcdserverpb::RangeResponse;
using string_map = std::unordered_map<std::string, std::string>;

namespace etcdv3
{
  class AsyncGetAction : public etcdv3::Action
  {
    public:
      AsyncGetAction(etcdv3::ActionParameters param, CompletionQueue* cq, unsigned long token);
      etcd::Response ParseResponse();
    private:
      RangeResponse reply;
      std::unique_ptr<ClientAsyncResponseReader<RangeResponse>> response_reader;
  };
}

#endif
