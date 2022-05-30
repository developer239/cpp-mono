#pragma once

#include "src/EventManager.h"
#include "src/Core.structs.h"

namespace LoopSDL {
  class EventManagerImplement : public Loop::EventManager {
    public:
      SDL_Event HandleInput(Loop::State& state) override;
  };
}