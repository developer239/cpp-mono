#include <SDL.h>
#include "App.h"

#include "systems/ScreenSystem.h"
#include "systems/RenderScreenSystem.h"
#include "events/KeyPressedEvent.h"
#include "systems/KeyboardControlSystem.h"

void App::OnSetup() {
  screen = new Screen(&state.window.width, &state.window.height, &appState.windowX, &appState.windowY);

  registry->AddSystem<ScreenSystem>();
  registry->AddSystem<RenderScreenSystem>();
  registry->AddSystem<KeyboardControlSystem>();
}

void App::OnInput(SDL_Event sdlEvent) {
  eventManager->eventBus->EmitEvent<KeyPressedEvent>(sdlEvent.key.keysym.sym);
}

void App::OnUpdate() {
  registry->GetSystem<KeyboardControlSystem>().SubscribeToEvents(eventManager->eventBus);
  registry->GetSystem<ScreenSystem>().Update(screen);
  registry->Update();
}

void App::OnRender() {
  registry->GetSystem<RenderScreenSystem>().Update(renderer->renderer, screen, &appState);
}
