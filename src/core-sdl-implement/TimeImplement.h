#pragma once

#include "../core/Tick.h"

class TimeImplement : public Tick {
  public:
    double GetTicks() override;
};
