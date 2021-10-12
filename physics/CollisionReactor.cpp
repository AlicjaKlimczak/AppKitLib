//
// Created by ala on 25/04/2021.
//

#include "CollisionReactor.h"

CollisionReactor::CollisionReactor(ObjectRegistry* objectRegistry) {
    this->objectRegistry = objectRegistry;
    this->eventHandlers = new map<tuple<int, int>, boost::function<bool(Object*, Object*)>>();
}

void CollisionReactor::registerCollisionListener(int from, int to, const boost::function<bool(Object *, Object *)> callback) {
    this->eventHandlers->emplace(make_tuple(from, to), callback);
}

bool CollisionReactor::registerMoveTo(Object *movingObject, int x, int y) {

    for (auto anotherObject : *objectRegistry->getObjects()) {
        if (movingObject != anotherObject && movingObject->isCollidingWith(x, y, anotherObject) && hasHandlerFor(movingObject, anotherObject)) {
            return callHandlers(movingObject, anotherObject);
        }
    }
    return true;
}

bool CollisionReactor::callHandlers(Object* from, Object* to) {
    auto handler = eventHandlers->find(make_tuple(from->getType(), to->getType()));

    if (handler != eventHandlers->end()) {
        return handler->second(from, to);
    }

    return true;
}

bool CollisionReactor::hasHandlerFor(Object *movingObject, Object *anotherObject) {
    return eventHandlers->find(make_tuple(movingObject->getType(), anotherObject->getType())) != eventHandlers->end();
}

