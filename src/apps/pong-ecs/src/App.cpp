#include "App.h"
#include "events/KeyPressedEvent.h"

void App::OnSetup() {
//  Entity hello = registry->CreateEntity();
//  hello.AddComponent<TextLabelComponent>(glm::vec2(20, 20), "Hello");
}

void App::OnInput(SDL_Event sdlEvent) {
  eventManager->eventBus->EmitEvent<KeyPressedEvent>(sdlEvent.key.keysym.sym);
}

void App::OnUpdate() {

  registry->Update();
}

void App::OnRender() {
}
