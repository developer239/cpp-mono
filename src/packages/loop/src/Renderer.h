#pragma once

#include "IApp.h"

namespace Loop {
  class Renderer {
    public:
      virtual void Initialize(int& width, int& height) = 0;

      virtual void Render(IApp* appInstance, void (IApp::* OnRender)()) = 0;
  };
}
