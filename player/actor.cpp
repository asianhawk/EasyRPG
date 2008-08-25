/* actor.cpp, actor routines.
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

//extern CWorld  * World; //cuando exista
#include "SDL.h"
#include "math-sll.h"
#include "sprite.h"
#include "actor.h"
#include "deltatime.h"


extern CDeltaTime System;
/*
metodos faltantes 

World->CollisionAt(GridX, GridY+1, WORLD_COLLISION_FROM_UP)



*/
#define ACTOR_STATE_IDLE        0x00
#define ACTOR_STATE_MOVING      0x01

#define ACTOR_DIRECTION_UP      0x00
#define ACTOR_DIRECTION_DOWN    0x01
#define ACTOR_DIRECTION_LEFT    0x02
#define ACTOR_DIRECTION_RIGHT   0x03

#define ACTOR_FLAGS_FREEZE      0x01

#define ACTOR_SPEED_SLOW        2.0f

int CActor::Clamp(int value, int min, int max) {
if(value<min)//mark when is out of range under development
{
outofarea=false;
return (min);}
else
if(value>max)
{outofarea=false;
return (max);
}
else
 {
 outofarea=true;
return (value);
 }

    return ((value<min)? min:(value>max)? max:value);
}
int CActor::Min(int value, int max) {
    return ((value>max)? max:value);
}


sll CActor::Minf(float value, float max) {
    return ((value>=max)? max:value);
}
sll CActor::Clampf(float value, float min, float max) {
    return ((value<min)? min:(value>=max)? max:value);
}
void CActor::setposXY(int x,int y)
{
 realX=(sll)x;
 realY=(sll)y;   
}
void CActor::MoveOnInput() {
    // In case the method was called and the actor is put on freeze
    // (for example, on message display or game pause)
    if (flags & ACTOR_FLAGS_FREEZE) return;

    
    // Depending on current actor state, select between accepting input
    // and Cmotion
    switch(state) {
        case ACTOR_STATE_IDLE:
          unsigned char * keyData;
     		  keyData = SDL_GetKeyState(NULL);
	  if ( keyData[SDLK_UP]  ){// && World->CollisionAt(GridX, GridY-1, WORLD_COLLISION_FROM_DOWN)==false) {
                state            = ACTOR_STATE_MOVING;
                Cmotion.direction = ACTOR_DIRECTION_UP;
                dir=0;
                Cmotion.distance  = 0;
            } else if (keyData[SDLK_DOWN]  ){// && World->CollisionAt(GridX, GridY+1, WORLD_COLLISION_FROM_UP)==false) {
                state            = ACTOR_STATE_MOVING;
                Cmotion.direction = ACTOR_DIRECTION_DOWN;
                dir=2;
                Cmotion.distance  = 0;
            } else if ( keyData[SDLK_LEFT] ){// && World->CollisionAt(GridX-1, GridY, WORLD_COLLISION_FROM_RIGHT)==false) {
                state            = ACTOR_STATE_MOVING;
                Cmotion.direction = ACTOR_DIRECTION_LEFT;
                dir=3;
                Cmotion.distance  = 0;
            } else if ( keyData[SDLK_RIGHT] ){ //&& World->CollisionAt(GridX+1, GridY, WORLD_COLLISION_FROM_LEFT)==false) {
                state            = ACTOR_STATE_MOVING;
                Cmotion.direction = ACTOR_DIRECTION_RIGHT;
                dir=1;
                Cmotion.distance  = 0;
            }else{frame=0;}
// 	    GridX = (x)>>4; GridY = (y)>>4;// Calculate Grid X and Grid Y
            break;
        case ACTOR_STATE_MOVING:
            // Calculate how many pixels has the actor travelled  and how many's left
            Cmotion.delta    =Clampf(ACTOR_SPEED_SLOW*System.deltaTime, 0, 16-Cmotion.distance); // Clampf(value, min, max)
            Cmotion.distance = Minf(Cmotion.distance+ACTOR_SPEED_SLOW*System.deltaTime, 16.0f);//Minf(distancia + movimiento, maximo )
            frameupdate();
            // Change position of character by adding the delta
            switch(Cmotion.direction) {
                case ACTOR_DIRECTION_UP:    realY=sllsub(realY, Cmotion.delta);  break;
                case ACTOR_DIRECTION_DOWN:  realY=slladd(realY, Cmotion.delta);  break;
                case ACTOR_DIRECTION_LEFT:  realX=sllsub(realX, Cmotion.delta);  break;
                case ACTOR_DIRECTION_RIGHT:  realX=slladd(realX, Cmotion.delta); break;
            }

               if (Cmotion.distance == 16.0f) state = ACTOR_STATE_IDLE;
             break;            
    }    
}
