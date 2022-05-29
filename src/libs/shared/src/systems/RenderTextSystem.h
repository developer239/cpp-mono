#pragma once

#include <SDL.h>
#include "src/System.h"
#include "../asset-store/AssetStore.h"

class RenderTextSystem : public System {
  public:
    RenderTextSystem();

    void Update(SDL_Renderer *renderer, std::unique_ptr<AssetStore> &assetStore);
};
