/*Skills_Menu_scene.cpp,Skills_Menu_Scene routines.
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

#include "Skills_Menu_scene.h"
/*
Skills_Menu_Scene::~Skills_Menu_Scene()
{
}
Skills_Menu_Scene:: Skills_Menu_Scene()
{
}
*/

void Skills_Menu_Scene::init(General_data * TheTeam)
{
	myteam=TheTeam;

    myaudio=&(TheTeam->musica);
	running=&TheTeam->running;
	NScene=&TheTeam->TheScene;

	int j;
	j=(*myteam).select;
	int k =(((*myteam).Players.get_skill_size(j)-1)/2);
   std::string system_string;
    system_string.append("System/");
    system_string.append(myteam->ldbdata->System_dat->System_graphic);
    system_string.append(".png");

	menu.init(myteam, running, 1,k, 320, 180, 0, 60,(char *)system_string.c_str());
	descripcion.init(320,30,0,0,(char *)system_string.c_str());
	descripcion2.init(320,30,0,30,(char *)system_string.c_str());

	int i;
	int space=16,Size_of_Block=150;
	char stringBuffer[255];
	sprintf(stringBuffer, " NV  %d  Normal  Hp %d / %d Mp %d / %d  ", ((*myteam).Players.get_Level(j)), ((*myteam).Players.get_HP(j)), ((*myteam).Players.get_MaxHP(j)), ((*myteam).Players.get_MP(j)), ((*myteam).Players.get_MaxMP(j)));
	descripcion2.add_text(((*myteam).Players.get_name(j)),10,5);
	descripcion2.add_text(stringBuffer,80,5);

	for(i=0;i<(*myteam).Players.get_skill_size(j);i++)
	{
		str_Vector.push_back( (const char *) ((*myteam).Players.get_skill_name(j,i)) );
		sprintf(stringBuffer, "%d ", (*((*myteam).Players.get_skill_mp_price(j,i))));
		menu.add_text(stringBuffer,Size_of_Block-10+((Size_of_Block+10)*((i)%(2))),5+((i/2)*space));
	}
	if(str_Vector.size()%2)//para que no truene si son nones
	{
		str_Vector.push_back( " " );
	}

	while(str_Vector.size()<2)//para que no truene si no hay nada
	{
		str_Vector.push_back( " " );
	}
	menu.setComands(& str_Vector);
	retardo=0;
}

void Skills_Menu_Scene::update(SDL_Surface* Screen)
{
	if(retardo==0)
	{
		menu.draw(Screen);
		descripcion.draw(Screen);
		descripcion2.draw(Screen);
		 myteam->screen_got_refresh=true;
	}
	retardo++;
	if(retardo==5)
	{
		menu.draw(Screen);
		descripcion.draw(Screen);
		retardo=1;
		 myteam->screen_got_refresh=true;
	}
}

void Skills_Menu_Scene::action()
{
/* if(menu.getindexY()==2)
  * running =false;
   if(menu.getindexY()==0)
    * NScene=1;     */
}

void Skills_Menu_Scene::updatekey()
{
	menu.updatekey();
	if(menu.desition())
	{
		action();
	}


        if(menu.menu.cancel)
        {
                    *NScene = 4;
        }

}

void Skills_Menu_Scene::dispose()
{
	menu.dispose();
	descripcion.dispose();
	descripcion2.dispose();
}
