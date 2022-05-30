#pragma once

#include <SDL.h>
#include "src/System.h"

class RenderRigidBodiesSystem : public System {
  public:
    RenderRigidBodiesSystem() {
      RequireComponent<RigidBodyComponent>();
    }

    void Update(SDL_Renderer* renderer) {
      for (auto entity: GetSystemEntities()) {
        auto rigidBodyComponent = entity.GetComponent<RigidBodyComponent>();

        SDL_Rect rect = {
            (int) rigidBodyComponent.position.x,
            (int) rigidBodyComponent.position.y,
            (int) rigidBodyComponent.width,
            (int) rigidBodyComponent.height
        };
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &rect);
      }
    }
};
