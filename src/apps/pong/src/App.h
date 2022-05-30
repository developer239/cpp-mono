#pragma once

#include <iostream>
#include "src/Core.h"
#include "entities/GameObject.h"

class App : public Loop::Core {
  public:
    GameObject ball = GameObject(
        15,
        15,
        20,
        20,
        300,
        300
    );
    GameObject paddle = GameObject(
        100,
        20,
        (state.window.width / 2) - (100 / 2),
        state.window.height - 40,
        0,
        0
    );

    App(
        std::shared_ptr<Loop::Tick> time, std::shared_ptr<Loop::Renderer> renderer,
        std::shared_ptr<Loop::EventManager> eventManager
    ) : Core(std::move(time), std::move(renderer), std::move(eventManager)) {
    }

    void OnSetup() override;

    void OnInput(SDL_Event keyCode) override;

    void OnUpdate() override;

    void OnRender() override;
};
