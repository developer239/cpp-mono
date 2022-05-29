#pragma once

#include "Core.structs.h"

// TODO: Linker doesn't work here for some reason 🤯
#include "../../events/src/Bus.h"

namespace Loop {
  class EventManager {
    public:
      std::unique_ptr<Events::Bus> eventBus;

      EventManager();

      void ResetEventBus() const;

      virtual void HandleInput(State& state, const std::shared_ptr<EventManager>& eventManager) = 0;
  };
}
