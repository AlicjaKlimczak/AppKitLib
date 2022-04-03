//
// Created by ala on 13/09/2020.
//

#ifndef APPKIT_TEXT_T_H
#define APPKIT_TEXT_T_H

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>
#include "Texture.h"
#include "../physics/Object.h"

class TextObject : public Texture, public Object {
private:
    TTF_Font* font;
    SDL_Color color;
    bool textHasBeenSet;
public:
    TextObject(string name, int type, ObjectRegistry *objectRegistry, Gfx *gfx, float posX, float posY, int fontSize, string fontFile);

    void setText(string text);
    void setTextAtPosition(string text, int x, int y);

    void render() override;

    SDL_FRect *getCoordinates() override;

    void tick() override;

};


#endif //APPKIT_TEXT_T_H
