//
// Created by ala on 25/04/2021.
//

#include "CollisionReactor.h"

CollisionReactor::CollisionReactor(ObjectRegistry *objectRegistry) {
    this->objectRegistry = objectRegistry;
    this->eventHandlers = new map<tuple<int, int>, boost::function<bool(shared_ptr<Object>, shared_ptr<Object>)>>();
}

void CollisionReactor::registerCollisionListener(int from, int to, const boost::function<bool(shared_ptr<Object>, shared_ptr<Object>)>& callback) {
    this->eventHandlers->emplace(make_tuple(from, to), callback);
}

bool CollisionReactor::registerMoveTo(const shared_ptr<Object>& movingObject, int x, int y) {

    for (const auto& anotherObject: *objectRegistry->getObjects()) {
        if (movingObject != anotherObject && movingObject->isCollidingWith(x, y, anotherObject) && hasHandlerFor(movingObject, anotherObject)) {
            return callHandlers(movingObject, anotherObject);
        }
    }
    return true;
}

bool CollisionReactor::callHandlers(const shared_ptr<Object>& from, const shared_ptr<Object>& to) {
    auto handler = eventHandlers->find(make_tuple(from->getType(), to->getType()));

    if (handler != eventHandlers->end()) {
        return handler->second(from, to);
    }

    return true;
}

bool CollisionReactor::hasHandlerFor(const shared_ptr<Object>& movingObject, const shared_ptr<Object>& anotherObject) {
    return eventHandlers->find(make_tuple(movingObject->getType(), anotherObject->getType())) != eventHandlers->end();
}

