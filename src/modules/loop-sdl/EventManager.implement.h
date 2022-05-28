#pragma once

#include "../../modules/loop/EventManager.h"

class EventManagerImplement: public EventManager {
  public:
    void HandleInput() override;
};
