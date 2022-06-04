#pragma once

#include <iostream>
#include "src/Core.h"
#include "src/Registry.h"
#include "src/AssetStore.h"
#include "src/Screen.h"
#include "services/AppState.h"

class App : public Loop::Core {
  public:
    AppState appState = AppState();
    Screen* screen;

    std::shared_ptr<Registry> registry;
    std::shared_ptr<AssetStore> assetStore;

    App(
        std::shared_ptr<Loop::Tick> time, std::shared_ptr<Loop::Renderer> renderer,
        std::shared_ptr<Loop::EventManager> eventManager
    ) : Core(std::move(time), std::move(renderer), std::move(eventManager)) {
      registry = std::make_shared<Registry>();
      assetStore = std::make_shared<AssetStore>();
    }

    ~App() {
      delete screen;
    }

    void OnSetup() override;

    void OnInput(SDL_Event keyCode) override;

    void OnUpdate() override;

    void OnRender() override;
};
