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
        std::shared_ptr<Loop::Tick> time, std::shared_ptr<Loop::Renderer> renderer,
        std::shared_ptr<Loop::EventManager> eventManager
    );

    void OnSetup() override;

    void OnInput() override;

    void OnUpdate() override;

    void OnRender() override;
};
