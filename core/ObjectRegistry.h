//
// Created by ala on 25/04/2021.
//

#ifndef APPKITLIB_OBJECTREGISTRY_H
#define APPKITLIB_OBJECTREGISTRY_H

class ObjectRegistry;

#include <string>
#include <list>
#include "../physics/Object.h"
#include "../gfx/Gfx.h"
#include "../physics/CollisionReactor.h"

using namespace std;

class ObjectRegistry {
private:
    Gfx *gfx;
    list<Object*> *objectList;
    CollisionReactor *collisionReactor;
public:
    explicit ObjectRegistry(Gfx *gfx);
    Object* createGfxObject(string name, int type, string texturesFile, int frameWidth, int posX, int posY, int width, int height);
    Object* createTextObject(string name, int type, int posX, int posY, int fontSize, string fontFile);

    void registerCollisionListener(int from, int to, const boost::function<bool(Object*, Object*)> callback);

    void renderObjects();

    list<Object*>* getObjects();

    void deleteObject(Object *object);

    CollisionReactor *getCollisionReactor();
};


#endif //APPKITLIB_OBJECTREGISTRY_H
