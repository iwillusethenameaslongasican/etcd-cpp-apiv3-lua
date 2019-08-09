set(CATCH_INCLUDE_DIR "../")
include_directories(${CATCH_INCLUDE_DIR})

add_executable(etcd_test test.cpp)
set_property(TARGET etcd_test PROPERTY CXX_STANDARD 11)

find_package(luna REQUIRED)

target_link_libraries(etcd_test etcd-cpp-api)

add_test(etcd_test etcd_test)