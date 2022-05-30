#pragma once

#include <SDL.h>

// TODO: Linker doesn't work here for some reason 🤯
#include "../../events/src/Bus.h"

#include "Core.structs.h"

namespace Loop {
  class EventManager {
    public:
      std::shared_ptr<Events::Bus> eventBus;

      EventManager();

      void ResetEventBus() const;

      // TODO: create interface for SDL_Event
      virtual SDL_Event HandleInput(Loop::State& state) = 0;
  };
}
