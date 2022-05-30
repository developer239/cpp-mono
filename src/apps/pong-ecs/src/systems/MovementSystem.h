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

    void Update(double deltaTime, Loop::State& state) {
      for (auto entity: GetSystemEntities()) {
        auto& rigidBodyComponent = entity.GetComponent<RigidBodyComponent>();

        // update entity position
        rigidBodyComponent.position.x += rigidBodyComponent.velocity.x * deltaTime;
        rigidBodyComponent.position.y += rigidBodyComponent.velocity.y * deltaTime;

        // fix entity position if it is out of bounds

        if (rigidBodyComponent.position.x < 0) {
          rigidBodyComponent.position.x = 0;

          if (entity.HasTag("Ball")) {
            rigidBodyComponent.velocity.x = -rigidBodyComponent.velocity.x;
          } else {
            rigidBodyComponent.velocity.x = 0;
          }
        }

        if (rigidBodyComponent.position.x + rigidBodyComponent.width > state.window.width) {
          rigidBodyComponent.position.x = state.window.width - rigidBodyComponent.width;

          if (entity.HasTag("Ball")) {
            rigidBodyComponent.velocity.x = -rigidBodyComponent.velocity.x;
          } else {
            rigidBodyComponent.velocity.x = 0;
          }
        }

        if (rigidBodyComponent.position.y < 0) {
          rigidBodyComponent.position.y = 0;

          if (entity.HasTag("Ball")) {
            rigidBodyComponent.velocity.y = -rigidBodyComponent.velocity.y;
          } else {
            rigidBodyComponent.velocity.y = 0;
          }
        }

        // TODO: this should probably live in a different system
        // check if game over
        if (rigidBodyComponent.position.y + rigidBodyComponent.height > state.window.height) {
          if (entity.HasTag("Ball")) {
            rigidBodyComponent.position.x = state.window.width / 2;
            rigidBodyComponent.position.y = 0;
          }
        }
      }
    }
};
