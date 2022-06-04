#pragma once

#include "src/Event.h"
#include "src/Entity.h"

class CollisionEvent : public Events::EventBase {
  public:
    Entity a;
    Entity b;

    CollisionEvent(Entity a, Entity b) : a(a), b(b) {
    }
};
