//
// Created by ala on 25/04/2021.
//

#include "ObjectRegistry.h"
#include "../gfx/GfxObject.h"
#include "../gfx/TextObject.h"

ObjectRegistry::ObjectRegistry(Gfx *gfx) {
    this->gfx = gfx;
    this->objectList = new list<Object*>();
    this->collisionReactor = new CollisionReactor(this);
}

void ObjectRegistry::renderObjects() {
    SDL_RenderClear(gfx->getRenderer());

    for (Object *object : *objectList) {
        object->render();
    }

    SDL_Delay(1000 / 60);
    SDL_RenderPresent(gfx->getRenderer());
}

Object* ObjectRegistry::createGfxObject(string name, int type, string texturesFile, int frameWidth, int posX, int posY, int width, int height) {
    auto *object = new GfxObject(name, type, this, gfx, texturesFile, frameWidth, posX, posY, width, height);
    objectList->push_back(object);

    return object;
}

Object *ObjectRegistry::createTextObject(string name, int type, int posX, int posY, int fontSize, string fontFile) {
    auto *object = new TextObject(name, type, this, gfx, posX, posY, fontSize, fontFile);
    objectList->push_back(object);

    return object;
}

list<Object*>* ObjectRegistry::getObjects() {
    return objectList;
}

void ObjectRegistry::registerCollisionListener(int from, int to, const boost::function<bool(Object *, Object *)> callback) {
    this->collisionReactor->registerCollisionListener(from, to, callback);
}

void ObjectRegistry::deleteObject(Object *object) {
    objectList->remove(object);
}

CollisionReactor *ObjectRegistry::getCollisionReactor() {
    return collisionReactor;
}
