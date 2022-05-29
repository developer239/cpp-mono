#pragma once

#include <memory>
#include "src/Bus.h"
#include "src/Logger.h"
#include "src/System.h"

#include "../events/KeyPressedEvent.h"

class KeyboardControlSystem : public System {
  public:
    void SubscribeToEvents() {
      Logger::Log("KeyboardControlSystem::SubscribeToEvents()");
    }

    void OnKeyPressed(KeyPressedEvent& event) {
      Logger::Log("KeyboardControlSystem: " + std::to_string(event.symbol) + " pressed");
    }
};
