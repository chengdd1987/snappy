#ifndef __SNAPPY_LUABINDING_H_
#define __SNAPPY_LUABINDING_H_

#if defined(_USRDLL)
#define LUA_EXTENSIONS_DLL     __declspec(dllexport)
#else         /* use a DLL library */
#define LUA_EXTENSIONS_DLL
#endif

#if (LUA_VERSION_NUM >= 502)
#undef luaL_register
#define luaL_register(L,n,f) \
               { if ((n) == NULL) luaL_setfuncs(L,f,0); else luaL_newlib(L,f); }

#endif

#if __cplusplus
extern "C" {
#endif

#include "lauxlib.h"

int LUA_EXTENSIONS_DLL luaopen_snappy(lua_State *L);

#if __cplusplus
}
#endif

#endif // __SNAPPY_LUABINDING_H_
