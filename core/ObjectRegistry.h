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
    list<shared_ptr<Object>> *objectList;
    CollisionReactor *collisionReactor;
    bool listOfObjectsChanged;
public:
    explicit ObjectRegistry(Gfx *gfx);

    Object* createTextObject(string name, int type, int posX, int posY, int fontSize, string fontFile);

    void addObject(shared_ptr<Object> object);

    void registerCollisionListener(int from, int to, boost::function<bool(shared_ptr<Object>, shared_ptr<Object>)> callback);

    void renderObjects();

    list<shared_ptr<Object>>* getObjects();

    void deleteObject(shared_ptr<Object> object);

    CollisionReactor *getCollisionReactor();

    void tick();
};


#endif //APPKITLIB_OBJECTREGISTRY_H
