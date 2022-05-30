#pragma once

#include <iostream>
#include <utility>
#include "Tick.h"
#include "Renderer.h"
#include "Core.structs.h"
#include "EventManager.h"

namespace Loop {
  class Core {
    public:
      State state;

      std::shared_ptr<Tick> time;
      std::shared_ptr<Renderer> renderer;
      std::shared_ptr<EventManager> eventManager;

      explicit Core(
          std::shared_ptr<Tick> time,
          std::shared_ptr<Renderer> renderer,
          std::shared_ptr<EventManager> eventManager
      );

      ~Core() = default;

      void Setup();

      void Run();

      void ProcessInput();

      void Update();

      void Render();

      virtual void OnSetup() = 0;

      // TODO: create interface for SDL_Event
      virtual void OnInput(SDL_Event keyCode) = 0;

      virtual void OnUpdate() = 0;

      virtual void OnRender() = 0;
  };
}
