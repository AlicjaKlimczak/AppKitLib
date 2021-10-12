//
// Created by ala on 25/04/2021.
//

#include "Gfx.h"
#include <SDL2/SDL_ttf.h>
#include "Texture.h"

using namespace std;

Gfx::Gfx(string title, int windowWidth, int windowHeight) {
    this->windowHeight = windowHeight;
    this->windowHeight = windowHeight;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    if (TTF_Init() != 0) {
        printf("error initializing TTF: %s\n", SDL_GetError());
    }
    /* Initialize only SDL Audio on default device */
    if(SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("error initializing Audio: %s\n", SDL_GetError());
    }

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, 0);

    // triggers the program that controls
    // your graphics hardware and sets flags
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images
    this->renderer = SDL_CreateRenderer(window, -1, render_flags);
}

void Gfx::setBackground(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_SetRenderDrawColor(renderer, r, g ,b, a);
}

SDL_Renderer *Gfx::getRenderer() {
    return renderer;
}

tuple<int, int> Gfx::getMousePosition() {
    int x, y;
    SDL_GetMouseState(&x, &y);
    return make_tuple(x, y);
}
