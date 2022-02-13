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
    map<tuple<int, int>, boost::function<bool(shared_ptr<Object>, shared_ptr<Object>)>> *eventHandlers;
public:
    explicit CollisionReactor(ObjectRegistry *objectRegistry);
    void registerCollisionListener(int from, int to, const boost::function<bool(shared_ptr<Object>, shared_ptr<Object>)>& callback);

    bool registerMoveTo(const shared_ptr<Object>& movingObject, int x, int y);

    bool callHandlers(const shared_ptr<Object>& from, const shared_ptr<Object>& to);

    bool hasHandlerFor(const shared_ptr<Object>& movingObject, const shared_ptr<Object>&anotherObject);
};

#endif //APPKITLIB_COLLISIONREACTOR_H