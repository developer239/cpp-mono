#pragma once

#include "../events/Bus.h"

class EventManager {
  public:
    std::unique_ptr<Events::Bus> eventBus;

    EventManager() {
      eventBus = std::make_unique<Events::Bus>();
    }

    void ResetEventBus() const;

    virtual void HandleInput() = 0;
};
