#include "App.h"
#include "src/Logger.h"
#include "systems/KeyboardControlSystem.h"

void App::Setup() {
  registry->AddSystem<KeyboardControlSystem>();
}

void App::OnUpdate() {
  registry->GetSystem<KeyboardControlSystem>().SubscribeToEvents(eventManager->eventBus);
  registry->Update();
}

void App::OnRender() {
  Logger::Log("App::OnRender()");
}
