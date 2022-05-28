#pragma once

#include <iostream>
#include <utility>
#include "Tick.h"
#include "Renderer.h"
#include "Loop.structs.h"
#include "EventManager.h"

class Loop {
  public:
    LoopState state;

    std::shared_ptr<Tick> time;
    std::shared_ptr<Renderer> renderer;
    std::shared_ptr<EventManager> eventManager;

    explicit Loop(
        std::shared_ptr<Tick> time,
        std::shared_ptr<Renderer> renderer,
        std::shared_ptr<EventManager> eventManager
    ) :
        time(std::move(time)),
        renderer(std::move(renderer)),
        eventManager(std::move(eventManager)) {
    }

    ~Loop() = default;

    void Setup() const;

    void Run();

    void ProcessInput() const;

    void Update() const;

    void Render();
};
