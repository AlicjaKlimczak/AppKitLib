//
// Created by ala on 13/09/2020.
//

#include <SDL2/SDL_image.h>
#include "iostream"

#include "Texture.h"
#include "../core/GameException.h"

using namespace std;


Texture::Texture(Gfx *gfx) {
    this->renderer = gfx->getRenderer();
    this->frame_width = 0;
}

Texture::Texture(Gfx* gfx, const char *file, int frame_width) {
    this->renderer = gfx->getRenderer();
    this->frame_width = frame_width;

    SDL_Surface *surface; // creates a surface to load an image into the main memory
    surface = IMG_Load(file); // please provide a path for your image
    if (surface == nullptr) {
        throw GameException(SDL_GetError());
    }

    this->frame_height = surface->h;
    this->game_texture = SDL_CreateTextureFromSurface(renderer, surface); // loads image to our graphics hardware memory.
    SDL_FreeSurface(surface); // clears main-memory

    coordinates.x = 0;
    coordinates.y = 0;

    SDL_QueryTexture(this->game_texture, nullptr, nullptr, &(coordinates.w), &(coordinates.h));
    center.x = coordinates.w / 2;
    center.y = coordinates.h / 2;
}

void Texture::setCoordinate(int x, int y) {
    this->coordinates.x = x;
    this->coordinates.y = y;
}

void Texture::setDimensions(int w, int h) {
    this->coordinates.w = w;
    this->coordinates.h = h;
}

SDL_Rect * Texture::getCoordinates() {
    return &coordinates;
}

SDL_Texture *Texture::get_texture() {
    return game_texture;
}

void Texture::render() {
    render(0);
}
void Texture::render(int frame) {
    SDL_Rect *frameDimensions = nullptr;
    if (frame_width != 0) {
        frameDimensions = new SDL_Rect();
        frameDimensions->x = frame_width * frame;
        frameDimensions->y = 0;
        frameDimensions->w = frame_width;
        frameDimensions->h = frame_height;
    }
    int result = SDL_RenderCopyEx(renderer, game_texture, frameDimensions, &coordinates, angle, &center, SDL_FLIP_NONE);

    delete frameDimensions;

    if (result != 0) {
        throw GameException(SDL_GetError());
    }
}

void Texture::set_rotation_angle(double rotation_angle) {
    this->angle = rotation_angle;
}

void Texture::set_center(int x, int y) {
    center.x = x;
    center.y = y;
}
