#pragma once

#include <iostream>
#include <thread>
#include "Renderer.h"

namespace LoopSDL {
  class RendererImplement : public Loop::Renderer {
    public:
      void Initialize() override;

      void Render() override;
  };
}