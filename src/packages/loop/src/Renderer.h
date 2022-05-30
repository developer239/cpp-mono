#pragma once

namespace Loop {
  class Renderer {
    public:
      virtual void Initialize(int& width, int& height) = 0;

      virtual void RenderStart() = 0;

      virtual void RenderEnd() = 0;
  };
}
