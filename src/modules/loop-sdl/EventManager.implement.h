#pragma once

#include "../../modules/loop/EventManager.h"

namespace LoopSDL {
  class EventManagerImplement : public Loop::EventManager {
    public:
      void HandleInput() override;
  };
}