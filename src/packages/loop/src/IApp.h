#pragma once

// TODO: Linker doesn't work here for some reason 🤯
#include "../../events/src/Bus.h"

namespace Loop {
  class IApp {
    public:
      std::shared_ptr<Events::Bus> eventBus;

      virtual void Setup() = 0;

      virtual void OnInput(int32_t keyCode) = 0;

      virtual void OnUpdate() = 0;

      virtual void OnRender() = 0;
  };
}
