#pragma once

#include "../modules/core/EventManager.h"

class EventManagerImplement: public EventManager {
  public:
    void HandleInput() override;
};
