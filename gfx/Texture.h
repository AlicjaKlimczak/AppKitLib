//
// Created by ala on 13/09/2020.
//

#ifndef APPKIT_TEXTURE_T_H
#define APPKIT_TEXTURE_T_H


#include <SDL2/SDL_render.h>

class Texture;

#include "Gfx.h"

class Texture {
private:
    SDL_Point center;
    int frame_width;
    int frame_height;
    double angle = 0;
protected:
    SDL_Renderer *renderer;
    SDL_Texture *game_texture;
    SDL_Rect coordinates;
public:
    explicit Texture(Gfx *gfx);
    explicit Texture(Gfx *gfx, const char *file, int frame_width);
    void setCoordinate(int x, int y);
    void setDimensions(int w, int h);

    SDL_Rect * getCoordinates();

    SDL_Texture *get_texture();

    void render();
    void render(int frame);

    void set_rotation_angle(double rotation_angle);

    void set_center(int x, int y);

};


#endif //APPKIT_TEXTURE_T_H
