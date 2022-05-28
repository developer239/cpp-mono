#pragma once

// TODO: Linker doesn't work here for some reason 🤯
#include "../events/Bus.h"

namespace Loop {
  class EventManager {
    public:
      std::unique_ptr<Events::Bus> eventBus;

      EventManager() {
        eventBus = std::make_unique<Events::Bus>();
      }

      void ResetEventBus() const;

      virtual void HandleInput() = 0;
  };
}
