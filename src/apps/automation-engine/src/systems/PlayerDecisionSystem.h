#pragma once

#include "src/Keyboard.h"
#include "../events/CollisionEvent.h"
#include "../components/BoundingBoxComponent.h"

struct IndexPositionMap {
  int index;
  int positionX;
};
int MIN_DELAY = 280;

class PlayerDecisionSystem : public System {
  public:
    PlayerDecisionSystem() {
      RequireComponent<BoundingBoxComponent>();
    }

    void Update(std::shared_ptr<Registry>& registry, std::shared_ptr<AppState>& appState) {
      //
      // Apple related logic start
      //

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

          if (actionIndex == -1) {
            continue;
          }

          if (collisionHappened && ticks - appState->actions[actionIndex].lastAt > MIN_DELAY) {
            if (ticks - appState->actions[actionIndex].lastAt > 100000) {
              Logger::Err("Fixing [apple] timestamp: " + std::to_string(ticks - appState->actions[actionIndex].lastAt));
              appState->actions[actionIndex].lastAt = SDL_GetTicks();
              continue;
            }

            if (area.HasTag("AreaTop")) {
              Logger::Log("AreaTop after " + std::to_string(ticks - appState->actions[actionIndex].lastAt) + " ms");
              Keyboard::ArrowUp();
            }
            if (area.HasTag("AreaMid")) {
              Logger::Log("AreaMid after " + std::to_string(ticks - appState->actions[actionIndex].lastAt) + " ms");
              Keyboard::ArrowRight();
            }
            if (area.HasTag("AreaBottom")) {
              Logger::Log("AreaBottom after " + std::to_string(ticks - appState->actions[actionIndex].lastAt) + " ms");
              Keyboard::ArrowDown();
            }

            appState->actions[actionIndex].lastAt = SDL_GetTicks();
          }
        }
      }

      //
      // Apple related logic end
      //

      //
      // Star related logic start
      //

      auto stars = registry->GetEntitiesByGroup("Star");
      auto areaBack = registry->GetEntityByTag("AreaBack");

      std::vector<IndexPositionMap> starPositions = {};

      for (int index = 0; index < stars.size(); index++) {
        auto star = stars[index];
        auto starBoundingBox = star.GetComponent<BoundingBoxComponent>();

        starPositions.push_back({ index, starBoundingBox.positionY });
      }

      std::sort(starPositions.begin(), starPositions.end(), [](IndexPositionMap a, IndexPositionMap b) {
        return a.positionX > b.positionX;
      });

      for (auto starPosition: starPositions) {
        auto star = stars[starPosition.index];
        auto starBoundingBox = star.GetComponent<BoundingBoxComponent>();
        auto areaBoundingBox = areaBack.GetComponent<BoundingBoxComponent>();

        bool collisionHappened = CheckAABBCollision(
            starBoundingBox.positionX,
            starBoundingBox.positionY,
            starBoundingBox.width,
            starBoundingBox.height,
            areaBoundingBox.positionX,
            areaBoundingBox.positionY,
            areaBoundingBox.width,
            areaBoundingBox.height
        );

        if (collisionHappened && ticks - appState->actions[3].lastAt > MIN_DELAY) {
          if (ticks - appState->actions[3].lastAt > 100000) {
            Logger::Err("Fixing [star] timestamp: " + std::to_string(ticks - appState->actions[3].lastAt));
            appState->actions[3].lastAt = SDL_GetTicks();
            continue;
          }

          Logger::Log("AreaBack after " + std::to_string(ticks - appState->actions[3].lastAt) + " ms");
          Keyboard::ArrowLeft();
          appState->actions[3].lastAt = SDL_GetTicks();
        }
      }

      //
      // Start related logic end
      //
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
