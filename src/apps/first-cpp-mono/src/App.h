#pragma once

#include <iostream>
#include "src/Core.h"
#include "src/Registry.h"
#include "src/AssetStore.h"

class App : public Loop::Core {
  public:
    std::shared_ptr<Registry> registry;
    std::shared_ptr<AssetStore> assetStore;

    App(
        std::shared_ptr<Loop::Tick> time, Loop::Renderer* renderer, std::shared_ptr<Loop::EventManager> eventManager
    ) : Core(std::move(time), renderer, std::move(eventManager)) {
      registry = std::make_shared<Registry>();
      assetStore = std::make_shared<AssetStore>();
    }

    void OnSetup() override;

    void OnInput(int32_t keyCode) override;

    void OnUpdate() override;

    void OnRender() override;
};
