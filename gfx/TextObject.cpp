//
// Created by ala on 13/09/2020.
//

#include "TextObject.h"
#include "SDL_ttf.h"
#include "../core/GameException.h"

TextObject::TextObject(string name, int type, ObjectRegistry *objectRegistry, Gfx *gfx, float posX, float posY, int fontSize, string fontFile) : Texture(gfx), Object(name, type, objectRegistry, posX, posY, 0, 0) {
    font = TTF_OpenFont(fontFile.c_str(), fontSize); //this opens a font style and sets a size
    if (font == nullptr) {
        throw GameException(SDL_GetError());
    }
    setCoordinate(posX, posY);
    setDimensions(0, 0);
    textHasBeenSet = false;
    color = {0, 0, 0};
}

void TextObject::setText(string text) {
    int w, h;

    if (text.length() <= 0 ) {
        textHasBeenSet = false;
        return;
    }

    textHasBeenSet = true;

    TTF_SizeText(font, text.c_str(), &w, &h);
    setDimensions(w, h);

    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface
    if (surface == nullptr) {
        throw GameException(SDL_GetError());
    }
    game_texture = SDL_CreateTextureFromSurface(renderer, surface); //now you can convert it into a texture
    SDL_FreeSurface(surface);
}

void TextObject::setTextAtPosition(string text, int x, int y) {
    setCoordinate(x, y);
    setText(text);
}

void TextObject::render() {
    if (textHasBeenSet) {
        Texture::render();
    }
}

SDL_FRect *TextObject::getCoordinates() {
    return Texture::getCoordinates();
}

void TextObject::tick() {
    //no-op as text is usually not moving
}


