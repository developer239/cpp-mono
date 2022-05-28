#pragma once

#include <iostream>
#include <thread>
#include "../modules/core/Renderer.h"

class RendererImplement : public Renderer {
  public:
    void Initialize() override;

    void Render() override;
};
