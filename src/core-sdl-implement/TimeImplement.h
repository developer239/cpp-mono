#pragma once

#include "../core/Time.h"

class TimeImplement : public Time {
  public:
    double GetTicks() override;
};
