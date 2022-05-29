#include "App.h"
#include "src/Logger.h"
#include "systems/KeyboardControlSystem.h"

App::App() {
  registry = std::make_shared<Registry>();
}

void App::OnInput(int32_t keyCode) {
  eventBus->EmitEvent<KeyPressedEvent>(keyCode);
}

void App::Setup() {
  registry->AddSystem<KeyboardControlSystem>();
}

void App::OnUpdate() {
  registry->GetSystem<KeyboardControlSystem>().SubscribeToEvents(eventBus);
  registry->Update();
}

void App::OnRender() {
  SDL_Delay(100);
}
