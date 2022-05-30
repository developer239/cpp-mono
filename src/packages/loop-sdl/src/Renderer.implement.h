#pragma once

#include <SDL.h>
#include <iostream>
#include <thread>
#include "src/Renderer.h"

namespace LoopSDL {
  class RendererImplement : public Loop::Renderer {
    private:
      SDL_Renderer* renderer;
      SDL_DisplayMode displayMode;
      SDL_Window* window;

    public:
      ~RendererImplement();

      void Initialize(int& width, int& height) override;

      void RenderStart() override;

      void RenderEnd() override;
  };
}
