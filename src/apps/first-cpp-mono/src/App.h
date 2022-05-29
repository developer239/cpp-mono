#pragma once

#include "src/IApp.h"

class App : public Loop::IApp {
  public:
    void Setup() override;

    void OnUpdate() override;

    void OnRender() override;
};
