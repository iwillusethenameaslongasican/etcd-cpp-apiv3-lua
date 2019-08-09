#include "etcd/Client.hpp"
#include "etcd/luna.h"


int create_etcd_client(lua_State *L) 
{
  const char *address = lua_tostring(L, 1);
  if (address == nullptr)
    return 0;

  Client *cli = new Client(L, address);
  lua_push_object(L, cli);
  return 1;
}

extern "C" int luaopen_libetcd(lua_State *L) {
  lua_newtable(L);
  lua_set_table_function(L, -1, "create_etcd_client", create_etcd_client);
  return 1;
}
