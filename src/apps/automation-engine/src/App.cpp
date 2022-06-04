#include <SDL.h>
#include "App.h"

#include "systems/PlayerDecisionSystem.h"
#include "systems/ScreenSystem.h"
#include "systems/RenderScreenSystem.h"
#include "events/KeyPressedEvent.h"
#include "systems/KeyboardControlSystem.h"
#include "systems/DetectionSystem.h"
#include "systems/RenderBoundingBoxSystem.h"
#include "systems/CollisionSystem.h"
#include "components/BoundingBoxComponent.h"

void App::OnSetup() {
  screen = std::make_unique<Screen>(&state.window.width, &state.window.height, &appState->windowX, &appState->windowY);

  registry->AddSystem<ScreenSystem>();
  registry->AddSystem<RenderScreenSystem>();
  registry->AddSystem<KeyboardControlSystem>();
  registry->AddSystem<DetectionSystem>();
  registry->AddSystem<RenderBoundingBoxSystem>();
  registry->AddSystem<CollisionSystem>();
  registry->AddSystem<PlayerDecisionSystem>(appState);

  Entity areaTop = registry->CreateEntity();
  areaTop.Tag("AreaTop");
  areaTop.AddComponent<BoundingBoxComponent>(175, 230, 140, 100);

  Entity areaMid = registry->CreateEntity();
  areaMid.Tag("AreaMid");
  areaMid.AddComponent<BoundingBoxComponent>(200, 358, 150, 10);

  Entity areaBottom = registry->CreateEntity();
  areaBottom.Tag("AreaBottom");
  areaBottom.AddComponent<BoundingBoxComponent>(200, 426, 150, 10);
}

void App::OnInput(SDL_Event sdlEvent) {
  eventManager->eventBus->EmitEvent<KeyPressedEvent>(sdlEvent.key.keysym.sym);
}

void App::OnUpdate() {
  registry->GetSystem<KeyboardControlSystem>().SubscribeToEvents(eventManager->eventBus);
  registry->GetSystem<PlayerDecisionSystem>().SubscribeToEvents(eventManager->eventBus);
  registry->Update();

  registry->GetSystem<ScreenSystem>().Update(screen);
  registry->GetSystem<DetectionSystem>().Update(screen, appState, registry);
  registry->GetSystem<CollisionSystem>().Update(appState, eventManager->eventBus);
}

void App::OnRender() {
  registry->GetSystem<RenderBoundingBoxSystem>().Update(renderer->renderer, screen, appState);
  registry->GetSystem<RenderScreenSystem>().Update(renderer->renderer, screen, appState);
}
