#pragma once

#include "Core.structs.h"
#include "IRenderable.h"

namespace Loop {
  class Renderer {
    public:
      Loop::State* state;

      virtual void Initialize(int& width, int& height) = 0;

      virtual void Render(IRenderable* appInstance, void (IRenderable::* OnRender)(State& state)) = 0;
  };
}
