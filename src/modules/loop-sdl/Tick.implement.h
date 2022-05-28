#pragma once

#include "../../modules/loop/Tick.h"

namespace LoopSDL {
  class TickImplement : public Loop::Tick {
    public:
      double GetTicks() override;
  };
}
