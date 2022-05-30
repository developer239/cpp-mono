#pragma once

#include "src/System.h"
#include "src/Bus.h"
#include "../events/CollisionEvent.h"
#include "../components/RigidBodyComponent.h"
#include "../components/KeyboardControlledComponent.h"
#include "../events/KeyPressedEvent.h"

class KeyboardControlSystem : public System {
  public:
    KeyboardControlSystem() {
      RequireComponent<KeyboardControlledComponent>();
    }

    void SubscribeToEvents(std::shared_ptr<Events::Bus>& eventBus) {
      eventBus->SubscribeToEvent<KeyPressedEvent>(this, &KeyboardControlSystem::OnKeyPressed);
    }

    void OnKeyPressed(KeyPressedEvent& event) {
      for (auto entity: GetSystemEntities()) {
        const auto keyboardControl = entity.GetComponent<KeyboardControlledComponent>();
        auto& rigidBody = entity.GetComponent<RigidBodyComponent>();

        switch (event.symbol) {
          case SDLK_UP:
            rigidBody.velocity = keyboardControl.upVelocity;
            break;
          case SDLK_RIGHT:
            rigidBody.velocity = keyboardControl.rightVelocity;
            break;
          case SDLK_DOWN:
            rigidBody.velocity = keyboardControl.downVelocity;
            break;
          case SDLK_LEFT:
            rigidBody.velocity = keyboardControl.leftVelocity;
            break;
        }
      }
    }

    void Update() {
    }
};
