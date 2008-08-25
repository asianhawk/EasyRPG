/* item.cpp, item routines.
   Copyright (C) 2007 EasyRPG Project <http://easyrpg.sourceforge.net/>.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#include <vector>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "sprite.h"
#include "key.h"
#include "font.h"
#include "audio.h"
#include "map.h"
#include "item.h"

void Item::set_NOI(int The_NOI)
{
   NOI=The_NOI;
}
int* Item::get_NOI()
{
   return (&NOI);
}
void Item::set_name(const char * name)
{
   nombre=name;
}
const char * Item::get_name()
{
   return(nombre);
}

void Item::set_type(unsigned char The_type)
{
   type=The_type;
}
unsigned char* Item::get_type()
{
   return (&type);
}
void Item::set_anim(Animacion the_anim)
{
   anim=the_anim;
}
Animacion * Item::get_anim()
{
   return (& anim);
}

