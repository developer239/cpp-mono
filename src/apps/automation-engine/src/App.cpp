#include <SDL.h>
#include "App.h"

#include "systems/PlayerDecisionSystem.h"
#include "systems/ScreenSystem.h"
#include "systems/RenderScreenSystem.h"
#include "events/KeyPressedEvent.h"
#include "systems/KeyboardControlSystem.h"
#include "systems/DetectionSystem.h"
#include "systems/RenderBoundingBoxSystem.h"
#include "components/BoundingBoxComponent.h"

void App::OnSetup() {
  screen = std::make_unique<Screen>(&state.window.width, &state.window.height, &appState->windowX, &appState->windowY);

  registry->AddSystem<ScreenSystem>();
  registry->AddSystem<RenderScreenSystem>();
  registry->AddSystem<KeyboardControlSystem>();
  registry->AddSystem<DetectionSystem>();
  registry->AddSystem<RenderBoundingBoxSystem>();
  registry->AddSystem<PlayerDecisionSystem>();

  Entity areaTop = registry->CreateEntity();
  areaTop.Tag("AreaTop");
  areaTop.Group("Area");
  areaTop.AddComponent<BoundingBoxComponent>(140, 230, 160, 105);

  Entity areaMid = registry->CreateEntity();
  areaMid.Tag("AreaMid");
  areaMid.Group("Area");
  areaMid.AddComponent<BoundingBoxComponent>(140, 358, 180, 7);

  Entity areaBottom = registry->CreateEntity();
  areaBottom.Tag("AreaBottom");
  areaBottom.Group("Area");
  areaBottom.AddComponent<BoundingBoxComponent>(140, 426, 180, 7);

  Entity areaBack = registry->CreateEntity();
  areaBack.Tag("AreaBack");
  areaBack.Group("Area");
  areaBack.AddComponent<BoundingBoxComponent>(37, 324, 28, 64);
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
