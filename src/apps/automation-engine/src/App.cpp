#include <SDL.h>
#include "App.h"

#include "systems/PlayerDecisionSystem.h"
#include "systems/ScreenSystem.h"
#include "systems/RenderScreenSystem.h"
#include "events/KeyPressedEvent.h"
#include "systems/KeyboardControlSystem.h"
#include "systems/DetectionSystem.h"
#include "systems/RenderBoundingBoxSystem.h"

void App::OnSetup() {
  screen = std::make_unique<Screen>(&state.window.width, &state.window.height, &appState->windowX, &appState->windowY);

  luaState->LoadSolScript("assets/scripts/strength.lua");

  registry->AddSystem<ScreenSystem>();
  registry->AddSystem<RenderScreenSystem>();
  registry->AddSystem<KeyboardControlSystem>();
  registry->AddSystem<DetectionSystem>();
  registry->AddSystem<RenderBoundingBoxSystem>();
  registry->AddSystem<PlayerDecisionSystem>();

  luaState->LoadEntities(registry);
}

void App::OnInput(SDL_Event sdlEvent) {
  eventManager->eventBus->EmitEvent<KeyPressedEvent>(sdlEvent.key.keysym.sym);
}

void App::OnUpdate() {
  registry->GetSystem<KeyboardControlSystem>().SubscribeToEvents(eventManager->eventBus);
  registry->Update();

  registry->GetSystem<ScreenSystem>().Update(screen);

  registry->GetSystem<DetectionSystem>().Update(screen, appState, registry);
  registry->GetSystem<PlayerDecisionSystem>().Update(registry, appState);
}

void App::OnRender() {
  registry->GetSystem<RenderBoundingBoxSystem>().Update(renderer->renderer, screen, appState);
  registry->GetSystem<RenderScreenSystem>().Update(renderer->renderer, screen, appState);
}
