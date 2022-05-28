#pragma once

#include "Tick.h"

namespace LoopSDL {
  class TickImplement : public Loop::Tick {
    public:
      double GetTicks() override;
  };
}
