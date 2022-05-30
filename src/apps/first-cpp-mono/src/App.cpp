#include "App.h"
#include "src/Logger.h"
#include "systems/KeyboardControlSystem.h"
#include "components/TextLabelComponent.h"
#include "systems/RenderTextSystem.h"

App::App() {
  registry = std::make_shared<Registry>();
  assetStore = std::make_shared<AssetStore>();
}

void App::OnInput(int32_t keyCode) {
  eventBus->EmitEvent<KeyPressedEvent>(keyCode);
}

void App::Setup() {
  registry->AddSystem<KeyboardControlSystem>();
  registry->AddSystem<RenderTextSystem>();

  assetStore->AddFont("pico8-font-10", "assets/fonts/pico8.ttf", 30);

  Entity hello = registry->CreateEntity();
  hello.AddComponent<TextLabelComponent>(glm::vec2(20, 20), "Hello");
}

void App::OnUpdate() {
  registry->GetSystem<KeyboardControlSystem>().SubscribeToEvents(eventBus);
  registry->Update();
}

void App::OnRender(Loop::State& state) {
//  registry->GetSystem<RenderTextSystem>().Update(renderer, assetStore);

  Logger::Log("Is running: " + std::to_string(state.isRunning));

  SDL_Delay(100);
}
