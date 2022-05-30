#pragma once

#include "src/System.h"
#include "../events/CollisionEvent.h"
#include "../components/RigidBodyComponent.h"

class MovementSystem : public System {
  public:
    MovementSystem() {
      RequireComponent<RigidBodyComponent>();
    }

    void SubscribeToEvents(const std::shared_ptr<Events::Bus>& eventBus) {
      eventBus->SubscribeToEvent<CollisionEvent>(this, &MovementSystem::OnCollision);
    }

    void OnCollision(CollisionEvent& event) {
    }

    void Update(double deltaTime) {
      for (auto entity: GetSystemEntities()) {
        auto& rigidBodyComponent = entity.GetComponent<RigidBodyComponent>();

        // update entity position
        rigidBodyComponent.position.x += rigidBodyComponent.velocity.x * deltaTime;
        rigidBodyComponent.position.y += rigidBodyComponent.velocity.y * deltaTime;
      }
    }
};
