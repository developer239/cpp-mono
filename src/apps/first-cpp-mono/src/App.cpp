#include "App.h"
#include "src/Logger.h"
#include "systems/KeyboardControlSystem.h"

App::App() {
  registry = std::make_shared<Registry>();
}

void App::Setup() {
  registry->AddSystem<KeyboardControlSystem>();
}

void App::OnUpdate() {
  registry->GetSystem<KeyboardControlSystem>().SubscribeToEvents(eventManager->eventBus);
  registry->Update();
}

void App::OnRender() {
  SDL_Delay(500);
}
