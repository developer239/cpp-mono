#pragma once

#include <iostream>
#include "src/IApp.h"
#include "src/Registry.h"

class App : public Loop::IApp {
  public:
    std::shared_ptr<Registry> registry;

    void Setup() override;

    void OnUpdate() override;

    void OnRender() override;
};
