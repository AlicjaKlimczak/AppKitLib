//
// Created by ala on 25/04/2021.
//

#ifndef APPKITLIB_GFX_H
#define APPKITLIB_GFX_H

class Gfx;

#include <SDL2/SDL.h>
#include <string>
#include <list>
#include <tuple>

using namespace std;

class Gfx {
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    int windowWidth;
    int windowHeight;
public:
    Gfx(string title, int windowWidth, int windowHeight);

    void setBackground(Uint8 r,Uint8 g,Uint8 b,Uint8 a);

    SDL_Renderer *getRenderer();

    tuple<int, int> getMousePosition();
};


#endif //APPKITLIB_GFX_H
