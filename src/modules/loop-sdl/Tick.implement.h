#pragma once

#include "../../modules/loop/Tick.h"

class TickImplement : public Loop::Tick {
  public:
    double GetTicks() override;
};
