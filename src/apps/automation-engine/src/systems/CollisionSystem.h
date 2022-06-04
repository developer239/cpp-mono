#pragma once

#include "src/Keyboard.h"

class CollisionSystem : public System {
  public:
    CollisionSystem() {
      RequireComponent<BoundingBoxComponent>();
    }

    void Update(AppState* state, const std::shared_ptr<Events::Bus>& eventBus) {
      auto entities = GetSystemEntities();

      // Loop all the entities that the system is interested in
      for (auto i = entities.begin(); i != entities.end(); i++) {
        Entity a = *i;
        auto aBoundingBox = a.GetComponent<BoundingBoxComponent>();

        // Loop all the entities that still need to be checked (to the right of i)
        for (auto j = i; j != entities.end(); j++) {
          Entity b = *j;

          // Bypass if we are trying to test the same entity
          if (a == b) {
            continue;
          }

          auto bBoundingBox = b.GetComponent<BoundingBoxComponent>();

          // Perform the AABB collision check between entities a and b
          bool collisionHappened = CheckAABBCollision(
              aBoundingBox.positionX,
              aBoundingBox.positionY,
              aBoundingBox.width,
              aBoundingBox.height,
              bBoundingBox.positionX,
              bBoundingBox.positionY,
              bBoundingBox.width,
              bBoundingBox.height
          );

          if (collisionHappened) {
            eventBus->EmitEvent<CollisionEvent>(a, b);
          }
        }
      }
    }

    bool CheckAABBCollision(double aX, double aY, double aW, double aH, double bX, double bY, double bW, double bH) {
      return (
          aX < bX + bW &&
          aX + aW > bX &&
          aY < bY + bH &&
          aY + aH > bY
      );
    }
};
