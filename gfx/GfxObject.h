//
// Created by ala on 25/04/2021.
//

#ifndef APPKITLIB_GFXOBJECT_H
#define APPKITLIB_GFXOBJECT_H

class GfxObject;

#include "Texture.h"
#include "string"
#include "Gfx.h"
#include "../core/ObjectRegistry.h"
#include "../physics/Object.h"

using namespace std;

class GfxObject : public Object {
private:
    shared_ptr<Texture> texture;
public:
    GfxObject(string name, int type, ObjectRegistry *objectRegistry, Gfx *gfx, string textureFile, int frameWidth, float posX, float posY, int width, int height);

    bool moveBy(float x, float y);

    void render() override;

    SDL_FRect *getCoordinates() override;

    void deleteObject() override;
};


#endif //APPKITLIB_GFXOBJECT_H
