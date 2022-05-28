#pragma once

#include "../../modules/loop/EventManager.h"

class EventManagerImplement : public Loop::EventManager {
  public:
    void HandleInput() override;
};
