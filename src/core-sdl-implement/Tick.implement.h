#pragma once

#include "../modules/core/Tick.h"

class TickImplement : public Tick {
  public:
    double GetTicks() override;
};
