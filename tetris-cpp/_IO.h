#ifndef _IO_
#define _IO_

#include "SDL/include/SDL.h"
#include "SDL/SDL_GfxPrimitives/sdl_gfxprimitives.h"
#pragma comment (lib, "SDL/lib/SDL.lib")
#pragma comment (lib, "SDL/SDL_GfxPrimitives/SDL_GfxPrimitives_Static.lib")

enum color {BLACK, RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW, WHITE, COLOR_MAX};

class IO{
    public:
        IO();

        void DrawRectangle(int x1, int y1, int x2, int y2, enum color color);
        void ClearScreen();
        int GetScreenHeight();
        int InitGraph();
        int Pollkey();
        int GetKey();
        int IsKeyDown(int pKey);
        void UpdateScreen();
};

#endif // _IO_