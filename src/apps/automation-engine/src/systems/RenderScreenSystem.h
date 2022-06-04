#pragma once

#include <SDL.h>
#include <opencv2/opencv.hpp>
#include "src/MatrixAsTexture.h"

class RenderScreenSystem : public System {
  public:
    RenderScreenSystem() = default;

    void Update(SDL_Renderer* renderer, std::unique_ptr<Screen>& screen, std::shared_ptr<AppState>& state) {
      MatrixAsTexture(renderer, screen->latestScreenshot);
    }
};
