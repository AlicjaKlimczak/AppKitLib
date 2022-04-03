//
// Created by ala on 25/04/2021.
//

#include "Object.h"
#include "SDL_rect.h"
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.

Object::Object(string name, int type, ObjectRegistry *objectRegistry, float posX, float posY, int width, int height) {
    this->objectRegistry = objectRegistry;
    this->objectName = name;
    this->objectType = type;
    this->uuid = boost::uuids::random_generator()();
}

bool Object::registerMoveTo(float x, float y) {
    return objectRegistry->getCollisionReactor()->registerMoveTo(shared_from_this(), x, y);
}

bool Object::isCollidingWith(float moveByX, float moveByY, shared_ptr<Object> anotherObject) {
    SDL_FRect *thisCoordinates = getCoordinates();
    SDL_FRect *anotherObjectsCoordinates = anotherObject->getCoordinates();
    int moveToX = thisCoordinates->x + moveByX;
    int moveToY = thisCoordinates->y + moveByY;
    if (moveToY >= anotherObjectsCoordinates->y && moveToY <= anotherObjectsCoordinates->y + anotherObjectsCoordinates->h
        || anotherObjectsCoordinates->y >= moveToY && anotherObjectsCoordinates->y <= moveToY + thisCoordinates->h) {
        if (moveToX >= anotherObjectsCoordinates->x && moveToX <= anotherObjectsCoordinates->x + anotherObjectsCoordinates->w
            || anotherObjectsCoordinates->x >= moveToX && anotherObjectsCoordinates->x <= moveToX + thisCoordinates->w) {
            return true;
        }
    }

    return false;
}

int Object::getType() {
    return this->objectType;
}

void Object::deleteObject() {
    objectRegistry->deleteObject(this->shared_from_this());
}

string Object::getName() {
    return objectName;
}

boost::uuids::uuid Object::getUuid() {
    return this->uuid;
}
