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
      ) :
          time(std::move(time)),
          renderer(std::move(renderer)),
          eventManager(std::move(eventManager)) {
      }

      ~Core() = default;

      void Setup();

      void Run();

      void ProcessInput();

      void Update() const;

      void Render();
  };
}