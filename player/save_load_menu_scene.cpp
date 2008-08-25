/* save_load_menu_scene.cpp, save load menu routines.
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
#include "math-sll.h"
#include "sprite.h"
#include "key.h"
#include "font.h"
#include "audio.h"
#include "map.h"
#include "skill.h"
#include "item.h"
#include "enemy.h"
#include "player.h"
#include "actor.h"
#include "scene.h"

void Save_Load_Menu_Scene::init(Audio * theaudio, bool * run,unsigned char * TheScene,Player_Team * TheTeam)
{    myteam=TheTeam;
     myaudio=theaudio;
  
   descripcion.init(320,30,0,0);
   descripcion.add_text("�D�nde deseas guardar la partida? ",10,5);
   Save_pos_1.init(320,70,0,30);
   Save_pos_2.init(320,70,0,100);
   Save_pos_3.init(320,70,0,170);
   running=  run;   
   NScene=TheScene;
     retardo=0;
}

void Save_Load_Menu_Scene::update(SDL_Surface* Screen)
{
retardo++;
if(retardo==6)
{  Save_pos_1.draw(Screen);
   Save_pos_2.draw(Screen);
   Save_pos_3.draw(Screen);
   descripcion.draw(Screen);  
   retardo=0;  
}       
}

void Save_Load_Menu_Scene::updatekey() {
  if (Key_press_and_realsed(LMK_X ))
        { (*myaudio).soundload("../Sound/Cansel2.wav");* NScene=4; }
     }
void Save_Load_Menu_Scene::dispose() {
   Save_pos_1.dispose();
   Save_pos_2.dispose();
   Save_pos_3.dispose();
   descripcion.dispose(); 
}
