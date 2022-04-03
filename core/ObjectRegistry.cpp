//
// Created by ala on 25/04/2021.
//

#include <iostream>
#include "ObjectRegistry.h"
#include "../gfx/GfxObject.h"
#include "../gfx/TextObject.h"

ObjectRegistry::ObjectRegistry(Gfx *gfx) {
    this->gfx = gfx;
    this->objectList = new list <shared_ptr<Object>>();
    this->collisionReactor = new CollisionReactor(this);
    this->listOfObjectsChanged = false;
}

void ObjectRegistry::renderObjects() {
    SDL_RenderClear(gfx->getRenderer());

    for (const shared_ptr <Object>& object: *objectList) {
        object->render();
    }

    SDL_Delay(1000 / 60);
    SDL_RenderPresent(gfx->getRenderer());
}

Object *ObjectRegistry::createTextObject(string name, int type, int posX, int posY, int fontSize, string fontFile) {
    auto *object = new TextObject(name, type, this, gfx, posX, posY, fontSize, fontFile);
    objectList->push_back(shared_ptr<TextObject>(object));

    return object;
}

list <shared_ptr<Object>> *ObjectRegistry::getObjects() {
    return objectList;
}

void ObjectRegistry::registerCollisionListener(int from, int to, const boost::function<bool(shared_ptr <Object>, shared_ptr<Object>)>& callback) {
    this->collisionReactor->registerCollisionListener(from, to, callback);
}

void ObjectRegistry::tick() {
    listOfObjectsChanged = false;

    for (const auto& o: *objectList) {
        o->tick();

        if (listOfObjectsChanged) {
            break;
        }
    }
}

void ObjectRegistry::deleteObject(const shared_ptr <Object>& object) {
    listOfObjectsChanged = true;
    objectList->remove(object);
    cout << "After remove size: " << objectList->size() << endl;
}

CollisionReactor *ObjectRegistry::getCollisionReactor() {
    return collisionReactor;
}

void ObjectRegistry::addObject(const shared_ptr <Object>& object) {
    objectList->push_back(object);
    cout << "After push_back size: " << objectList->size() << endl;
}
