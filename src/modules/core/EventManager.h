#pragma once

#include "../event-bus/EventBus.h"

class EventManager {
  public:
    std::unique_ptr<EventBus> eventBus;

    EventManager() {
      eventBus = std::make_unique<EventBus>();
    }

    void ResetEventBus() const;

    virtual void HandleInput() = 0;
};
