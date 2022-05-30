#pragma once

#include <memory>
#include "src/Bus.h"
#include "src/Logger.h"
#include "src/System.h"

#include "../events/KeyPressedEvent.h"

class KeyboardControlSystem : public System {
  public:
    void SubscribeToEvents(const std::shared_ptr<Events::Bus>& eventBus) {
      eventBus->SubscribeToEvent<KeyPressedEvent>(this, &KeyboardControlSystem::OnKeyPressed);
    }

    void OnKeyPressed(KeyPressedEvent& event) {
      Logger::Log("KeyboardControlSystem: " + std::to_string(event.symbol) + " pressed");
    }
};
