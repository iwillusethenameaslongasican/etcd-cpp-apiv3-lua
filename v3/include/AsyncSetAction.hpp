#ifndef __ASYNC_SET_HPP__
#define __ASYNC_SET_HPP__

#include <grpc++/grpc++.h>
#include "proto/rpc.grpc.pb.h"
#include "v3/include/Action.hpp"
#include "v3/include/AsyncTxnResponse.hpp"
#include "etcd/Response.hpp"

#include <unordered_map>
#include <vector>

using grpc::ClientAsyncResponseReader;
using etcdserverpb::TxnResponse;
using etcdserverpb::KV;
using string_map = std::unordered_map<std::string, std::string>;

namespace etcdv3
{
  class AsyncSetAction : public etcdv3::Action
  {
    public:
      AsyncSetAction(etcdv3::ActionParameters param, CompletionQueue* cq, unsigned long token, bool create=false);
      etcd::Response ParseResponse();
    private:
      TxnResponse reply;
      std::unique_ptr<ClientAsyncResponseReader<TxnResponse>> response_reader;
      bool isCreate;
  };
}

#endif
