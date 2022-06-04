#pragma once

#include "src/Keyboard.h"
#include "../events/CollisionEvent.h"

class PlayerDecisionSystem : public System {
  public:
    AppState* appState;

    explicit PlayerDecisionSystem(AppState* appState) : appState(appState) {
    }

    void SubscribeToEvents(const std::shared_ptr<Events::Bus>& eventBus) {
      eventBus->SubscribeToEvent<CollisionEvent>(this, &PlayerDecisionSystem::OnCollision);
    }

    void OnCollision(CollisionEvent& event) {
      Entity a = event.a;
      Entity b = event.b;

      auto ticks = SDL_GetTicks();
      int minDelay = 323;

      sort(appState->actions.begin(), appState->actions.end(), [](const Action& a, const Action& b) {
        return a.lastAt - b.lastAt;
      });

      for (Action& action: appState->actions) {
        if (
            (a.HasTag(action.areaType) || b.HasTag(action.areaType))
            && ticks - action.lastAt > minDelay
            ) {
          if (action.areaType == "AreaTop") {
            Keyboard::ArrowUp();
            action.lastAt = SDL_GetTicks();
          }

          if (action.areaType == "AreaMid") {
            Keyboard::ArrowRight();
            action.lastAt = SDL_GetTicks();
          }

          if (action.areaType == "AreaBottom") {
            Keyboard::ArrowDown();
            action.lastAt = SDL_GetTicks();
          }
          Logger::Log(action.areaType);
        }
      }
    }
};
