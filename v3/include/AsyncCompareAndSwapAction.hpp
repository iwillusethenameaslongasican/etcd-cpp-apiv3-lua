#ifndef __ASYNC_COMPAREANDSWAP_HPP__
#define __ASYNC_COMPAREANDSWAP_HPP__

#include <grpc++/grpc++.h>
#include "proto/rpc.grpc.pb.h"
#include "v3/include/Action.hpp"
#include "v3/include/AsyncTxnResponse.hpp"
#include "etcd/Response.hpp"

#include <unordered_map>
#include <string>

using grpc::ClientAsyncResponseReader;
using etcdserverpb::TxnResponse;
using etcdserverpb::KV;
using string_map = std::unordered_map<std::string, std::string>;

namespace etcdv3
{
  class AsyncCompareAndSwapAction : public etcdv3::Action
  {
    public:
      AsyncCompareAndSwapAction(etcdv3::ActionParameters param, etcdv3::Atomicity_Type type, CompletionQueue* cq, unsigned long token);
      etcd::Response ParseResponse();
    private:
      TxnResponse reply;
      std::unique_ptr<ClientAsyncResponseReader<TxnResponse>> response_reader;
  };
}

#endif
