//
// Created by ala on 25/04/2021.
//

#include "Object.h"
#include "SDL_rect.h"

Object::Object(string name, int type, ObjectRegistry *objectRegistry, int posX, int posY, int width, int height) {
    this->objectRegistry = objectRegistry;
    this->objectName = name;
    this->objectType = type;
}

bool Object::registerMoveTo(int x, int y) {
    return objectRegistry->getCollisionReactor()->registerMoveTo(this, x, y);
}

bool Object::isCollidingWith(int moveByX, int moveByY, Object *anotherObject) {
    SDL_Rect *thisCoordinates = getCoordinates();
    SDL_Rect *anotherObjectsCoordinates = anotherObject->getCoordinates();
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
    objectRegistry->deleteObject(this);
}

string Object::getName() {
    return objectName;
}
