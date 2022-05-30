#pragma once

#include "IApp.h"

namespace Loop {
  class Renderer {
    public:
      Loop::State* state;

      virtual void Initialize(int& width, int& height) = 0;

      virtual void Render(IApp* appInstance, void (IApp::* OnRender)(State& state)) = 0;
  };
}
