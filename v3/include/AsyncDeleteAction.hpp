#ifndef __ASYNC_DELETE_HPP__
#define __ASYNC_DELETE_HPP__

#include <grpc++/grpc++.h>
#include "proto/rpc.grpc.pb.h"
#include "v3/include/Action.hpp"
#include "v3/include/AsyncDeleteRangeResponse.hpp"
#include "etcd/Response.hpp"

#include <unordered_map>
#include <string>

using grpc::ClientAsyncResponseReader;
using etcdserverpb::DeleteRangeResponse;
using string_map = std::unordered_map<std::string, std::string>;

namespace etcdv3
{
  class AsyncDeleteAction : public etcdv3::Action
  {
    public:
      AsyncDeleteAction(etcdv3::ActionParameters param, CompletionQueue* cq, unsigned long token);
      etcd::Response ParseResponse();
    private:
      DeleteRangeResponse reply;
      std::unique_ptr<ClientAsyncResponseReader<DeleteRangeResponse>> response_reader;
  };
}

#endif
