#include "App.h"

#include <utility>
#include "systems/KeyboardControlSystem.h"
#include "components/TextLabelComponent.h"
#include "systems/RenderTextSystem.h"

void App::OnSetup() {
  registry->AddSystem<KeyboardControlSystem>();
  registry->AddSystem<RenderTextSystem>();

  assetStore->AddFont("pico8-font-10", "assets/fonts/pico8.ttf", 30);

  Entity hello = registry->CreateEntity();
  hello.AddComponent<TextLabelComponent>(glm::vec2(20, 20), "Hello");
}

void App::OnInput(SDL_Event sdlEvent) {
  eventManager->eventBus->EmitEvent<KeyPressedEvent>(sdlEvent.key.keysym.sym);
}

void App::OnUpdate() {
  registry->GetSystem<KeyboardControlSystem>().SubscribeToEvents(eventManager->eventBus);
  registry->Update();
}

void App::OnRender() {
  registry->GetSystem<RenderTextSystem>().Update(renderer->renderer, assetStore);
}
