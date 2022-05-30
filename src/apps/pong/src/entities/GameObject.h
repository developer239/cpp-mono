#pragma once

#include <SDL.h>
#include "src/Renderer.h"

struct GameObject {
  float x;
  float y;
  float width;
  float height;
  float velX;
  float velY;

  explicit GameObject(
      float width = 0,
      float height = 0,
      float x = 0,
      float y = 0,
      float vel_x = 0,
      float vel_y = 0
  ) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->velX = vel_x;
    this->velY = vel_y;
  }

  void Render(Loop::Renderer& renderer) const {
    SDL_Rect rect = {
        (int) this->x,
        (int) this->y,
        (int) this->width,
        (int) this->height
    };
    SDL_SetRenderDrawColor(renderer.renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer.renderer, &rect);
  }
};
