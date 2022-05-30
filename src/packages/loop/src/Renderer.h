#pragma once

#include <SDL.h>

namespace Loop {
  class Renderer {
    public:
      // TODO: implement interfaces for these properties before creating loop-opengl
      SDL_Renderer* renderer;
      SDL_DisplayMode displayMode;
      SDL_Window* window;

      virtual void Initialize(int& width, int& height) = 0;

      virtual void RenderStart() = 0;

      virtual void RenderEnd() = 0;
  };
}
