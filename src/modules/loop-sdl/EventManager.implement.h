#pragma once

#include "EventManager.h"

namespace LoopSDL {
  class EventManagerImplement : public Loop::EventManager {
    public:
      void HandleInput() override;
  };
}