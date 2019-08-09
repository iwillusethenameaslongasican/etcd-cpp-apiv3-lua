add_library(etcd SHARED ../proto/kv.pb.cc ../proto/auth.pb.cc ../proto/rpc.pb.cc ../proto/rpc.grpc.pb.cc ../v3/src/AsyncTxnResponse.cpp ../v3/src/AsyncRangeResponse.cpp ../v3/src/Transaction.cpp ../v3/src/action_constants.cpp ../v3/src/AsyncSetAction.cpp ../v3/src/AsyncCompareAndSwapAction.cpp ../v3/src/AsyncUpdateAction.cpp ../v3/src/AsyncGetAction.cpp ../v3/src/AsyncDeleteAction.cpp ../v3/src/AsyncCompareAndDeleteAction.cpp ../v3/src/Action.cpp ../v3/src/AsyncWatchAction.cpp ../v3/src/V3Response.cpp ../v3/src/AsyncDeleteRangeResponse.cpp ../v3/src/AsyncWatchResponse.cpp ../v3/src/AsyncLeaseGrantResponse.cpp ../v3/src/AsyncLeaseGrantAction.cpp ../v3/src/KeyValue.cpp Client.cpp Response.cpp Value.cpp Watcher.cpp main.cpp)
set_property(TARGET etcd PROPERTY CXX_STANDARD 11)

target_link_libraries(etcd ssl crypto protobuf grpc++)

install (TARGETS etcd DESTINATION lib)
install (FILES ../etcd/Client.hpp
               ../etcd/Response.hpp
               ../etcd/Value.hpp
               ../etcd/Watcher.hpp
               DESTINATION include/etcd)

