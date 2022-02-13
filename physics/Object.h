//
// Created by ala on 25/04/2021.
//

#ifndef APPKITLIB_OBJECT_H
#define APPKITLIB_OBJECT_H

#include <string>
#include <SDL_rect.h>
#include "../core/ObjectRegistry.h"
#include <boost/uuid/uuid.hpp>

using namespace std;

class Object : public enable_shared_from_this<Object> {
private:
    boost::uuids::uuid uuid;
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

    bool isCollidingWith(int moveByX, int moveByY, shared_ptr<Object> anotherObject);

    virtual void deleteObject();

    boost::uuids::uuid getUuid();

    virtual void tick() = 0;
};


#endif //APPKITLIB_OBJECT_H
