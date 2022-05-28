#pragma once

#include "../../modules/loop/Tick.h"

class TickImplement : public Tick {
  public:
    double GetTicks() override;
};
