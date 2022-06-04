#pragma once

#include "src/Keyboard.h"
#include "../events/CollisionEvent.h"
#include "../components/BoundingBoxComponent.h"

struct IndexPositionMap {
  int index;
  int positionX;
};

int MIN_DELAY = 375;

class PlayerDecisionSystem : public System {
  public:
    PlayerDecisionSystem() {
      RequireComponent<BoundingBoxComponent>();
    }

    void Update(std::shared_ptr<Registry>& registry, std::shared_ptr<AppState>& appState) {
      auto ticks = SDL_GetTicks();

      auto areas = registry->GetEntitiesByGroup("Area");
      auto apples = registry->GetEntitiesByGroup("Apple");

      std::vector<IndexPositionMap> applePositions = {};

      for (int index = 0; index < apples.size(); index++) {
        auto apple = apples[index];
        auto appleBoundingBox = apple.GetComponent<BoundingBoxComponent>();

        applePositions.push_back({ index, appleBoundingBox.positionX });
      }

      std::sort(applePositions.begin(), applePositions.end(), [](IndexPositionMap a, IndexPositionMap b) {
        return a.positionX < b.positionX;
      });

      for (auto applePosition: applePositions) {
        auto apple = apples[applePosition.index];
        auto appleBoundingBox = apple.GetComponent<BoundingBoxComponent>();

        for (auto area: areas) {
          auto areaBoundingBox = area.GetComponent<BoundingBoxComponent>();

          bool collisionHappened = CheckAABBCollision(
              appleBoundingBox.positionX,
              appleBoundingBox.positionY,
              appleBoundingBox.width,
              appleBoundingBox.height,
              areaBoundingBox.positionX,
              areaBoundingBox.positionY,
              areaBoundingBox.width,
              areaBoundingBox.height
          );

          int actionIndex = -1;

          if (area.HasTag("AreaTop")) {
            actionIndex = 0;
          }
          if (area.HasTag("AreaMid")) {
            actionIndex = 1;
          }
          if (area.HasTag("AreaBottom")) {
            actionIndex = 2;
          }

          if (collisionHappened && ticks - appState->actions[actionIndex].lastAt > MIN_DELAY) {
            if (area.HasTag("AreaTop")) {
              Keyboard::ArrowUp();
            }
            if (area.HasTag("AreaMid")) {
              Keyboard::ArrowRight();
            }
            if (area.HasTag("AreaBottom")) {
              Keyboard::ArrowDown();
            }

            appState->actions[actionIndex].lastAt = SDL_GetTicks();
          }
        }
      }
    }

    bool CheckAABBCollision(double aX, double aY, double aW, double aH, double bX, double bY, double bW, double bH) {
      return (
          aX < bX + bW &&
          aX + aW > bX &&
          aY < bY + bH &&
          aY + aH > bY
      );
    }
};
