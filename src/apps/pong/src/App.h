#pragma once

#include <iostream>
#include "src/Core.h"

class App : public Loop::Core {
  public:
    App(
        std::shared_ptr<Loop::Tick> time, std::shared_ptr<Loop::Renderer> renderer,
        std::shared_ptr<Loop::EventManager> eventManager
    ) : Core(std::move(time), std::move(renderer), std::move(eventManager)) {
    }

    void OnSetup() override;

    void OnInput(int32_t keyCode) override;

    void OnUpdate() override;

    void OnRender() override;
};
