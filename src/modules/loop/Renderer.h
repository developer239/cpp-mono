#pragma once

namespace Loop {
  class Renderer {
    public:
      virtual void Initialize(int& width, int& height) = 0;

      virtual void Render() = 0;
  };
}
