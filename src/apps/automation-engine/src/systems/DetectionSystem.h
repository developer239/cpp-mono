#pragma once

#include "../components/BoundingBoxComponent.h"

class DetectionSystem : public System {
  public:
    DetectionSystem() = default;

    // TODO: remove registry and access entities with "this"
    void Update(std::unique_ptr<Screen>& screen, std::shared_ptr<AppState>& state, std::shared_ptr<Registry> registry) {
      cv::Mat latestScreenShotDebug = screen->latestScreenshot->clone();

      if (state->shouldDetectColors) {
        DetectColors(latestScreenShotDebug, state);
      }

      if (state->shouldErodeDilate) {
        ErodeDilate(latestScreenShotDebug, state);
      }

      if (state->shouldFindContours && latestScreenShotDebug.channels() == 1) {
        FindContours(latestScreenShotDebug, registry);
      }

      if (latestScreenShotDebug.channels() == 1) {
        cv::cvtColor(latestScreenShotDebug, latestScreenShotDebug, cv::COLOR_GRAY2BGR);
      }
    }

  private:
    void DetectColors(cv::Mat& inputMatrix, std::shared_ptr<AppState>& state) {
      cv::inRange(
          inputMatrix,
          cv::Scalar(state->lowerRed, state->lowerGreen, state->lowerBlue),
          cv::Scalar(state->upperRed, state->upperGreen, state->upperBlue),
          inputMatrix
      );
    }

    void ErodeDilate(cv::Mat& inputMatrix, std::shared_ptr<AppState>& state) {
      cv::morphologyEx(
          inputMatrix,
          inputMatrix,
          cv::MORPH_OPEN,
          cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(state->morphologyWidth, state->morphologyHeight))
      );
    }

    // TODO: optimize memory management
    void FindContours(cv::Mat& inputMatrix, std::shared_ptr<Registry>& registry) {
      std::vector<std::vector<cv::Point>> contours;

      cv::findContours(
          inputMatrix,
          contours,
          cv::RETR_TREE,
          cv::CHAIN_APPROX_SIMPLE
      );

      std::vector<std::vector<cv::Point>> contoursVector(contours.size());
      std::vector<cv::Rect> boundRect(contours.size());
      std::vector<cv::Point2f> centers(contours.size());

      for (auto entity: registry->GetEntitiesByGroup("Apple")) {
        entity.Kill();
      }

      for (size_t i = 0; i < contours.size(); i++) {
        approxPolyDP(contours[i], contoursVector[i], 10, true);
        auto rect = boundingRect(contours[i]);

        if (rect.width > 22 && rect.height > 22) {
          Entity match = registry->CreateEntity();
          match.Group("Apple");
          match.AddComponent<BoundingBoxComponent>(rect.x, rect.y, rect.width, rect.height);
        }

      }
    }
};
