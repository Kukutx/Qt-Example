// registerfunctions.h

#ifndef REGISTERFUNCTIONS
#define REGISTERFUNCTIONS
#include<QString>
#include <cmath>
//  加载lua头文件
#include "lua/src/lua.hpp"
typedef int (*luaTestFunction)(lua_State *L);
// 第一步：定义lua调用的函数
static int myadd(lua_State* L)
{
    double op1 = lua_tonumber(L, 1);
    double op2 = lua_tonumber(L, 2);
    lua_pushnumber(L, op1 + op2);
    return 1;
}

static int mysub(lua_State* L)
{
    double op1 = lua_tonumber(L, 1);
    double op2 = lua_tonumber(L, 2);
    lua_pushnumber(L, op1 - op2);
    return 1;
}


static int l_sin(lua_State *L)
{
    // 如果给定虚拟栈中索引处的元素可以转换为数字，则返回转换后的数字，否则报错。
    double d = luaL_checknumber(L, 1);
    lua_pushnumber(L, sin(d));  /* push result */

    /* 这里可以看出，C可以返回给Lua多个结果，
     * 通过多次调用lua_push*()，之后return返回结果的数量。
     */
    return 1;  /* number of results */
}


int myprint( lua_State* L )
{
    //...
    Q_UNUSED(L);
    return 0;
}

//提供的接口函数
const int TestFUNCNUM = 4;
const luaTestFunction MFUNC_P[] =
{
    myadd,
    mysub,
    l_sin,
    myprint
};

const QString MACROFUNCNAME[] =
{
    "cadd",
    "csub",
    "csin",
    "myprint"
};



#ifdef USING_LUA_REGISTER
//待Lua调用的C注册函数。
static int add2(lua_State* L)
{
    //检查栈中的参数是否合法，1表示Lua调用时的第一个参数(从左到右)，依此类推。
    //如果Lua代码在调用时传递的参数不为number，该函数将报错并终止程序的执行。
    double op1 = luaL_checknumber(L,1);
    double op2 = luaL_checknumber(L,2);
    //将函数的结果压入栈中。如果有多个返回值，可以在这里多次压入栈中。
    lua_pushnumber(L,op1 + op2);
    //返回值用于提示该C函数的返回值数量，即压入栈中的返回值数量。
    return 1;
}

//另一个待Lua调用的C注册函数。
static int sub2(lua_State* L)
{
    double op1 = luaL_checknumber(L,1);
    double op2 = luaL_checknumber(L,2);
    lua_pushnumber(L,op1 - op2);
    return 1;
}
#endif



#endif // REGISTERFUNCTIONS
