#pragma once

#include <SDL.h>

class RenderBoundingBoxSystem : public System {
  public:
    RenderBoundingBoxSystem() {
      RequireComponent<BoundingBoxComponent>();
    }

    void Update(SDL_Renderer* renderer, Screen* screen, AppState* state) {
      cv::Mat* latestScreenShot = screen->latestScreenshot;

      for (auto entity: GetSystemEntities()) {
        auto component = entity.GetComponent<BoundingBoxComponent>();

        cv::Scalar color = cv::Scalar(0, 255, 255);
        cv::rectangle(*latestScreenShot, cv::Point2i(component.positionX, component.positionY),
                      cv::Point2i(component.positionX + component.width, component.positionY + component.height), color,
                      2);
      }
    }
};
