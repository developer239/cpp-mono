#pragma once

#include "../components/BoundingBoxComponent.h"

class DetectionSystem : public System {
  public:
    DetectionSystem() = default;

    // TODO: remove registry and access entities with "this"
    void Update(std::unique_ptr<Screen>& screen, std::shared_ptr<AppState>& state, std::shared_ptr<Registry>& registry) {
      for (auto& target: state->targets) {
        cv::Mat latestScreenShotDebug = screen->latestScreenshot->clone();

        if (target.detectColorsArguments.has_value()) {
          DetectColors(
              latestScreenShotDebug,
              target.detectColorsArguments->lowerRed,
              target.detectColorsArguments->lowerGreen,
              target.detectColorsArguments->lowerBlue,
              target.detectColorsArguments->upperRed,
              target.detectColorsArguments->upperGreen,
              target.detectColorsArguments->upperBlue
          );
        }

        if (target.erodeDilateArguments.has_value()) {
          ErodeDilate(
              latestScreenShotDebug,
              target.erodeDilateArguments->morphologyWidth,
              target.erodeDilateArguments->morphologyHeight
          );
        }

        // only run if detected colors or eroded dilated
        if (latestScreenShotDebug.channels() == 1) {
          FindContours(latestScreenShotDebug, registry, target);

          // fix channels after morphological operations
          cv::cvtColor(latestScreenShotDebug, latestScreenShotDebug, cv::COLOR_GRAY2BGR);
        }
      }
    }

  private:
    void DetectColors(
        cv::Mat& inputMatrix, int lowerRed, int lowerGreen, int lowerBlue, int upperRed, int upperGreen, int upperBlue
    ) {
      cv::inRange(
          inputMatrix,
          cv::Scalar(lowerRed, lowerGreen, lowerBlue),
          cv::Scalar(upperRed, upperGreen, upperBlue),
          inputMatrix
      );
    }

    void ErodeDilate(cv::Mat& inputMatrix, int morphologyWidth, int morphologyHeight) {
      cv::morphologyEx(
          inputMatrix,
          inputMatrix,
          cv::MORPH_OPEN,
          cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(morphologyWidth, morphologyHeight))
      );
    }

    void FindContours(cv::Mat& inputMatrix, std::shared_ptr<Registry>& registry, Target& target) {
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

      for (auto entity: registry->GetEntitiesByGroup(target.tag)) {
        entity.Kill();
      }

      for (size_t i = 0; i < contours.size(); i++) {
        approxPolyDP(contours[i], contoursVector[i], 10, true);
        auto rect = boundingRect(contours[i]);

        if (rect.width > target.detectColorsArguments->minWidth && rect.height > target.detectColorsArguments->minHeight) {
          Entity match = registry->CreateEntity();
          match.Group(target.tag);
          match.AddComponent<BoundingBoxComponent>(rect.x, rect.y, rect.width, rect.height);
        }
      }
    }
};
