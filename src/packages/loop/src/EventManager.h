#pragma once

// TODO: Linker doesn't work here for some reason 🤯
#include "../../events/src/Bus.h"

#include "IApp.h"
#include "Core.structs.h"

namespace Loop {
  class EventManager {
    public:
      std::shared_ptr<Events::Bus> eventBus;

      EventManager();

      void ResetEventBus() const;

      virtual void HandleInput(State& state, IApp* appInstance, void (IApp::* OnInput)(int32_t keyCode)) = 0;
  };
}
