/* tools.cpp, miscellaneous shared routines.
   Copyright (C) 2007 EasyRPG Project <http://easyrpg.sourceforge.net/>.
   se encarga de la laectura de enteros con comprecion Ber
   La carga y creacin de superficies

  */

    // =========================================================================
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include "tools.h"
    using namespace std;
    // =========================================================================
    
    unsigned long ReadCompressedInteger(FILE * FileStream)
    {
        unsigned long Value = 0;
        unsigned char Temporal = 0;
        
        // int i = 0;
        do
        {
            Value <<= 7;
            
            // Get byte's value
            fread(&Temporal, sizeof(char), 1, FileStream);
            
            // Check if it's a BER integer
            Value |= Temporal&0x7F;
            
        } while (Temporal&0x80);
        
        return Value;
    }
   int CountRead(int data)//por esto tools deveria ser una clase
   {static int count;
   if(data != -1)
   count=data;
   return (count);
   }
    
     unsigned long ReadCompressedIntegerCount(FILE * FileStream)
    {
        unsigned long Value = 0;
        unsigned char Temporal = 0;
       int sizeread=0;
        // int i = 0;
        do
        {
            Value <<= 7;
            
            // Get byte's value
            fread(&Temporal, sizeof(char), 1, FileStream);
            sizeread++;
            // Check if it's a BER integer
            Value |= Temporal&0x7F;
            
        } while (Temporal&0x80);
        CountRead (sizeread);
        return Value;
    }
    
    
    
    
    string ReadString(FILE * FileStream)
    {
        unsigned char Length;
        char        * Characters;
        string        String;
        
        // Read string lenght's
        fread(&Length, sizeof(char), 1, FileStream);
        if (Length == 0) return string("");
        
        // Allocate string buffer
        Characters = new char[Length+1];
        memset(Characters, 0, Length+1);
        fread(Characters, sizeof(char), Length, FileStream);
        
        // Get string and free characters buffer
        String = string(Characters);
        delete Characters;
        
        return String;
    }

    string ReadString(FILE * FileStream, unsigned char Length)
    {
        char        * Characters;
        string        String;
        
        // Allocate string buffer
        Characters = new char[Length+1];
        memset(Characters, 0, Length+1);
        fread(Characters, sizeof(char), Length, FileStream);
        
        // Get string and free characters buffer
        String = string(Characters);
        delete Characters;
        
        return String;
    }
/*

    SDL_Surface * CreateSurface(int Width, int Height)
    {
        SDL_Surface * dummySurface = NULL;
        SDL_Surface * realSurface = NULL;
        SDL_Color color;
        Uint32 colorKey;

        dummySurface = SDL_CreateRGBSurface(SDL_SRCCOLORKEY, Width, Height, 8, 0, 0, 0, 0);
        if (!dummySurface) return NULL;

        SetTransparent(dummySurface);

        realSurface  = SDL_DisplayFormat(dummySurface);
        if ( !realSurface ) return NULL;

        color = dummySurface->format->palette->colors[0];
        colorKey = SDL_MapRGB(realSurface->format, color.r, color.g, color.b);
        SDL_SetColorKey(realSurface, SDL_SRCCOLORKEY, colorKey);

        SDL_FreeSurface(dummySurface);

        if ( !realSurface ) return NULL;
        SDL_FillRect(realSurface, NULL, 0);

        return realSurface;

    }
    
    SDL_Surface * LoadSurface(string Filename)
    {       
        SDL_Surface * dummySurface = NULL;
        SDL_Surface * realSurface = NULL;
        SDL_Color color;
        Uint32 colorKey;
        
        dummySurface = IMG_Load(Filename.c_str());
        if (!dummySurface) return NULL;

        SetTransparent(dummySurface);
        
        realSurface  = SDL_DisplayFormat(dummySurface);
        if ( !realSurface ) return NULL;

        color = dummySurface->format->palette->colors[0];
        colorKey = SDL_MapRGB(realSurface->format, color.r, color.g, color.b);
        SDL_SetColorKey(realSurface, SDL_SRCCOLORKEY, colorKey);

        SDL_FreeSurface(dummySurface);
        
        return realSurface;
    }
    
    void DrawSurface(SDL_Surface * Destiny, int dX, int dY, SDL_Surface * Source, int sX, int sY, int sW, int sH)
    {
        if (sW == -1) sW = Source->w;
        if (sH == -1) sH = Source->h;
        
        SDL_Rect sourceRect;
        sourceRect.x = sX;
        sourceRect.y = sY;
        sourceRect.w = sW;
        sourceRect.h = sH;
        
        SDL_Rect destinyRect;
        destinyRect.x = dX;
        destinyRect.y = dY;
        destinyRect.w = sW;
        destinyRect.h = sH;
        
        SDL_BlitSurface(Source, &sourceRect, Destiny, &destinyRect);
    }

    SDL_Surface * GrabFromSurface(SDL_Surface * Source, int sX, int sY, int sW, int sH)
    {
        SDL_Surface * Return = CreateSurface(16, 16);
        DrawSurface(Return, 0, 0, Source, sX, sY, sW, sH);
        
        return Return;
    }
*/
