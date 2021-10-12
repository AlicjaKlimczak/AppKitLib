//
// Created by ala on 25/04/2021.
//

#ifndef APPKITLIB_OBJECT_H
#define APPKITLIB_OBJECT_H

#include <string>
#include <SDL_rect.h>
#include "../core/ObjectRegistry.h"

using namespace std;

class Object {
private:
    ObjectRegistry *objectRegistry;
    string objectName;
    int objectType;
public:

    Object(string name, int type, ObjectRegistry *objectRegistry, int posX, int posY, int width, int height);

    virtual SDL_Rect *getCoordinates() = 0;

    virtual void render() = 0;

    bool registerMoveTo(int x, int y);

    int getType();

    string getName();

    bool isCollidingWith(int moveByX, int moveByY, Object *anotherObject);

    virtual void deleteObject();
};


#endif //APPKITLIB_OBJECT_H
