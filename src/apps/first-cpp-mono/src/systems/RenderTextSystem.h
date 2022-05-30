#pragma once

#include <SDL.h>
#include "src/System.h"
#include "src/AssetStore.h"
#include "../components/TextLabelComponent.h"

class RenderTextSystem : public System {
  public:
    RenderTextSystem() {
      RequireComponent<TextLabelComponent>();
    }

    void Update(SDL_Renderer* renderer, std::shared_ptr<AssetStore>& assetStore) {
      for (auto entity: GetSystemEntities()) {
        const auto textLabelComponent = entity.GetComponent<TextLabelComponent>();

        SDL_Surface* surface = TTF_RenderText_Blended(
            assetStore->GetFont(textLabelComponent.fontId),
            textLabelComponent.text.c_str(),
            textLabelComponent.color
        );
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);

        int labelWidth = 0;
        int labelHeight = 0;

        SDL_QueryTexture(texture, nullptr, nullptr, &labelWidth, &labelHeight);
        SDL_Rect dstRect = {
            static_cast<int>(textLabelComponent.position.x),
            static_cast<int>(textLabelComponent.position.y),
            labelWidth,
            labelHeight
        };
        SDL_RenderCopy(renderer, texture, nullptr, &dstRect);

        SDL_DestroyTexture(texture);
      }
    }
};
