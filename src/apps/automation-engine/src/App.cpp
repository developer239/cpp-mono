#include <SDL.h>
#include "App.h"

#include "systems/ScreenSystem.h"
#include "systems/RenderScreenSystem.h"
#include "events/KeyPressedEvent.h"
#include "systems/KeyboardControlSystem.h"
#include "systems/DetectionSystem.h"
#include "systems/RenderBoundingBoxSystem.h"
#include "systems/ScriptSystem.h"

int lastA = 0;

void App::OnSetup() {
  // Read directly from source so you don't have to rebuild
  lua->LoadSolScript("../../../../src/apps/automation-engine/assets/scripts/strength.lua");

  lua->LoadWindowPosition(appState);

  screen = std::make_unique<Screen>(&state.window.width, &state.window.height, &appState->windowX, &appState->windowY);

  registry->AddSystem<ScreenSystem>();
  registry->AddSystem<RenderScreenSystem>();
  registry->AddSystem<KeyboardControlSystem>();
  registry->AddSystem<DetectionSystem>();
  registry->AddSystem<RenderBoundingBoxSystem>();
  registry->AddSystem<ScriptSystem>(lua, registry);

  registry->GetSystem<ScriptSystem>().CreateLuaBindings();

  lua->LoadEntities(registry);
  lua->LoadTargets(appState);
}

void App::OnInput(SDL_Event sdlEvent) {
  eventManager->eventBus->EmitEvent<KeyPressedEvent>(sdlEvent.key.keysym.sym);
}

void App::OnUpdate() {
  registry->GetSystem<KeyboardControlSystem>().SubscribeToEvents(eventManager->eventBus);
  registry->Update();

  registry->GetSystem<ScreenSystem>().Update(screen);
  registry->GetSystem<DetectionSystem>().Update(screen, appState, registry);

  if(time->msPreviousFrame - lastA > 400) {
    registry->GetSystem<ScriptSystem>().Update();
    lastA = time->msPreviousFrame;
  }
}

void App::OnRender() {
  registry->GetSystem<RenderBoundingBoxSystem>().Update(renderer->renderer, screen, appState);
  registry->GetSystem<RenderScreenSystem>().Update(renderer->renderer, screen, appState);
}
