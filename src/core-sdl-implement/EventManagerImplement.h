#pragma once

#include "../core/EventManager.h"

class EventManagerImplement: public EventManager {
  public:
    void HandleInput() override;
};
