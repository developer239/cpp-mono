#pragma once

#include "src/System.h"
#include "src/Entity.h"
#include "src/Bus.h"
#include "src/Logger.h"
#include "../components/RigidBodyComponent.h"
#include "../components/BoxColliderComponent.h"
#include "../events/CollisionEvent.h"

class CollisionSystem : public System {
  public:
    CollisionSystem() {
      RequireComponent<RigidBodyComponent>();
      RequireComponent<BoxColliderComponent>();
    }

    void Update(const std::shared_ptr<Events::Bus>& eventBus) {
      auto entities = GetSystemEntities();

      for (auto i = entities.begin(); i != entities.end(); i++) {
        Entity a = *i;
        auto aRigidBody = a.GetComponent<RigidBodyComponent>();
        auto aCollider = a.GetComponent<BoxColliderComponent>();

        for (auto j = i; j != entities.end(); j++) {
          Entity b = *j;

          if (a == b) {
            continue;
          }

          auto bRigidBody = b.GetComponent<RigidBodyComponent>();
          auto bCollider = b.GetComponent<BoxColliderComponent>();

          bool collisionHappened = CheckAABBCollision(
              aRigidBody.position.x + aCollider.offset.x,
              aRigidBody.position.y + aCollider.offset.y,
              aCollider.width,
              aCollider.height,
              bRigidBody.position.x + bCollider.offset.x,
              bRigidBody.position.y + bCollider.offset.y,
              bCollider.width,
              bCollider.height
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
