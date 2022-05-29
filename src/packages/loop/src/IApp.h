#pragma once

#include "EventManager.h"

namespace Loop {
  class IApp {
    public:
      std::shared_ptr<EventManager> eventManager;

      virtual void Setup() = 0;

      virtual void OnUpdate() = 0;

      virtual void OnRender() = 0;
  };
}
