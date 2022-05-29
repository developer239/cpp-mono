#pragma once

#include <iostream>
#include "src/IApp.h"
#include "src/Registry.h"

class App : public Loop::IApp {
  public:
    std::shared_ptr<Registry> registry;

    App();

    void Setup() override;

    void OnInput(int32_t keyCode) override;

    void OnUpdate() override;

    void OnRender() override;
};
