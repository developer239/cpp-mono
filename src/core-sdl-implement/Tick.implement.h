#pragma once

#include "../core/Tick.h"

class TickImplement : public Tick {
  public:
    double GetTicks() override;
};
