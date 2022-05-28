#pragma once

#include <iostream>
#include <utility>
#include "Time.h"
#include "Renderer.h"
#include "Loop.structs.h"

class Loop {
  public:
    LoopState state;

    std::shared_ptr<Time> time;
    std::shared_ptr<Renderer> renderer;

    explicit Loop(
        std::shared_ptr<Time> time,
        std::shared_ptr<Renderer> renderer
    ) :
        time(std::move(time)),
        renderer(std::move(renderer)) {
    }

    ~Loop() = default;

    void Setup() const;

    void Run();

    void ProcessInput();

    void Update() const;

    void Render();
};
