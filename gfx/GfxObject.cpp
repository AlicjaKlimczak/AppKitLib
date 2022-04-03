//
// Created by ala on 25/04/2021.
//

#include "string"
#include "GfxObject.h"

GfxObject::GfxObject(string name, int type, ObjectRegistry *objectRegistry, Gfx *gfx, string textureFile, int frameWidth, float posX, float posY, int width, int height) : Object(name, type, objectRegistry, posX, posY, width, height) {
    texture = shared_ptr<Texture>(new Texture(gfx, textureFile.c_str(), frameWidth));
    texture->setDimensions(width, height);
    texture->setCoordinate(posX, posY);
}

bool GfxObject::moveBy(float x, float y) {
    bool canMoveTo = Object::registerMoveTo(x, y);

    if (canMoveTo) {
        texture->setCoordinate(texture->getCoordinates()->x + x, texture->getCoordinates()->y + y);
    }

    return canMoveTo;
}

void GfxObject::render() {
    texture->render();
}

SDL_FRect* GfxObject::getCoordinates() {
    return texture->getCoordinates();
}

void GfxObject::deleteObject() {
    Object::deleteObject();
}
