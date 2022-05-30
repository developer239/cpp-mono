#pragma once

#include <iostream>
#include <utility>
#include "Tick.h"
#include "Renderer.h"
#include "Core.structs.h"
#include "EventManager.h"
#include "IApp.h"

namespace Loop {
  class Core {
    public:
      State state;

      std::shared_ptr<Tick> time;
      std::shared_ptr<Renderer> renderer;
      std::shared_ptr<EventManager> eventManager;
      std::shared_ptr<IApp> app;

      explicit Core(
          std::shared_ptr<Tick> time,
          std::shared_ptr<Renderer> renderer,
          std::shared_ptr<EventManager> eventManager,
          std::shared_ptr<IApp> app
      ) :
          time(std::move(time)),
          eventManager(std::move(eventManager)) {
        this->renderer = std::move(renderer);
        this->renderer->state = this->state;

        this->app = std::move(app);
        this->app->eventBus = this->eventManager->eventBus;
      }

      ~Core() = default;

      void Setup();

      void Run();

      void ProcessInput();

      void Update() const;

      void Render();
  };
}
