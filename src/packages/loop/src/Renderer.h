#pragma once

#include "IApp.h"

namespace Loop {
  class Renderer {
    public:
      virtual void Initialize(int& width, int& height) = 0;

      virtual void Render(IApp* myClass, void (IApp::* OnRender)()) = 0;
  };
}
