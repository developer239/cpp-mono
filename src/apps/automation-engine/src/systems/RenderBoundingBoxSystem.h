#pragma once

#include <SDL.h>

class RenderBoundingBoxSystem : public System {
  public:
    RenderBoundingBoxSystem() {
      RequireComponent<BoundingBoxComponent>();
    }

    void Update(SDL_Renderer* renderer, std::unique_ptr<Screen>& screen, std::shared_ptr<AppState>& state) {
      auto latestScreenShot = screen->latestScreenshot;

      for (auto entity: GetSystemEntities()) {
        auto component = entity.GetComponent<BoundingBoxComponent>();

        cv::Scalar color = cv::Scalar(0, 255, 255);
        cv::rectangle(*latestScreenShot, cv::Point2i(component.positionX, component.positionY),
                      cv::Point2i(component.positionX + component.width, component.positionY + component.height), color,
                      2);
      }
    }
};
