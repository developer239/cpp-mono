#ifndef LOOP_H
#define LOOP_H

#include <iostream>
#include <utility>
#include "Time.h"
#include "Loop.structs.h"

class Loop {
  public:
    std::shared_ptr<Time> time;
    LoopState state;

    explicit Loop(std::shared_ptr<Time> time) : time(std::move(time)) {
    }

    ~Loop() = default;

    void Setup();

    void Run();

    void ProcessInput();

    void Update() const;

    void Render();
};

#endif
