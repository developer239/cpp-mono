#pragma once

#include <string>
#include "src/System.h"
#include "src/Bus.h"
#include "src/Logger.h"
#include "../events/KeyPressedEvent.h"

class KeyboardControlSystem : public System {
  public:
    KeyboardControlSystem() = default;

    void SubscribeToEvents(std::shared_ptr<Events::Bus>& eventBus) {
      eventBus->SubscribeToEvent<KeyPressedEvent>(this, &KeyboardControlSystem::OnKeyPressed);
    }

    void OnKeyPressed(KeyPressedEvent& event) {
    }
};
