/*
   This file is part of darktable,
   copyright (c) 2012 Jeremy Rosen

   darktable is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   darktable is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with darktable.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef DT_LUA_GLIST_H
#define DT_LUA_GLIST_H
#include <lualib.h>
#include <lua.h>
#include <lautoc.h>
#include <glib.h>



int dt_lua_init_glist(lua_State * L);

// handle list of data who's elementes are type_name* (!!not type_name casted)
#define dt_lua_push_glist(L,list, type_name,reverse) dt_lua_push_glist_typeid(L,list,luaA_type_id(type_name),reverse)
void dt_lua_push_glist_typeid(lua_State *L,GList * list, luaA_Type elt_type,bool reverse);

// return a malloced list who's elements are malloced type_name*
#define dt_lua_to_glist(L,list, type_name,index) dt_lua_to_glist_internal(L,list,luaA_type_id(type_name),index)
GList* dt_lua_to_glist_typeid(lua_State *L, luaA_Type elt_type,int index);
#endif

// modelines: These editor modelines have been set for all relevant files by tools/update_modelines.sh
// vim: shiftwidth=2 expandtab tabstop=2 cindent
// kate: tab-indents: off; indent-width 2; replace-tabs on; indent-mode cstyle; remove-trailing-space on;
