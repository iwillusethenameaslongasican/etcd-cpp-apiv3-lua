#ifndef __ASYNC_WATCHACTION_HPP__
#define __ASYNC_WATCHACTION_HPP__

#include <grpc++/grpc++.h>
#include "proto/rpc.grpc.pb.h"
#include "v3/include/Action.hpp"
#include "v3/include/AsyncWatchResponse.hpp"
#include "etcd/Response.hpp"


using grpc::ClientAsyncReaderWriter;
using etcdserverpb::WatchRequest;
using etcdserverpb::WatchResponse;


namespace etcdv3
{
  class AsyncWatchAction : public etcdv3::Action
  {
    public:
      AsyncWatchAction(etcdv3::ActionParameters param, CompletionQueue* cq = nullptr, unsigned long token = 0);
      etcd::Response ParseResponse();
      int events_size();
      void read();
      void CancelWatch();
      void WatchReq(std::string const & key);
      
      bool isCancelled = false;
    private:
      WatchResponse reply;
      WatchRequest watch_req;
      std::unique_ptr<ClientAsyncReaderWriter<WatchRequest,WatchResponse>> stream;   
      unsigned long m_token;
  };
}

#endif
