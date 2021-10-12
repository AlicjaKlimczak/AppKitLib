//
// Created by ala on 25/04/2021.
//

#ifndef APPKITLIB_COLLISIONREACTOR_H
#define APPKITLIB_COLLISIONREACTOR_H

class CollisionReactor;

#include <map>
#include <string>
#include "boost/function.hpp"
#include "../physics/Object-partial.h"
#include "../core/ObjectRegistry.h"

using namespace std;

class CollisionReactor {
private:
    ObjectRegistry *objectRegistry;
    map<tuple<int, int>, boost::function<bool(Object*, Object*)>> *eventHandlers;
public:
    explicit CollisionReactor(ObjectRegistry *objectRegistry);
    void registerCollisionListener(int from, int to, const boost::function<bool(Object*, Object*)> callback);

    bool registerMoveTo(Object *movingObject, int x, int y);

    bool callHandlers(Object* from, Object* to);

    bool hasHandlerFor(Object *movingObject, Object *anotherObject);
};

#endif //APPKITLIB_COLLISIONREACTOR_H