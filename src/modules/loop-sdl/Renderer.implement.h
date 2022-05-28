#pragma once

#include <iostream>
#include <thread>
#include "../../modules/loop/Renderer.h"

class RendererImplement : public Renderer {
  public:
    void Initialize() override;

    void Render() override;
};
