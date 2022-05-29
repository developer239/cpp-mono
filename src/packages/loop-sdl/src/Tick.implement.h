#pragma once

#include "src/Tick.h"

namespace LoopSDL {
  class TickImplement : public Loop::Tick {
    public:
      double GetTicks() override;
  };
}
