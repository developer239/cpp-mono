#include "App.h"
#include "events/KeyPressedEvent.h"
#include "components/RigidBodyComponent.h"
#include "systems/RenderRigidBodiesSystem.h"
#include "systems/MovementSystem.h"
#include "systems/KeyboardControlSystem.h"

void App::OnSetup() {
  registry->AddSystem<MovementSystem>();
  registry->AddSystem<RenderRigidBodiesSystem>();
  registry->AddSystem<KeyboardControlSystem>();

  Entity ball = registry->CreateEntity();
  ball.Tag("Ball");
  ball.AddComponent<RigidBodyComponent>(
      15,
      15,
      glm::vec2(20.0, 20.0),
      glm::vec2(300.0, 300.0)
  );

  Entity paddle = registry->CreateEntity();
  ball.Tag("Paddle");
  paddle.AddComponent<KeyboardControlledComponent>(
      glm::vec2(0, 0),
      glm::vec2(400, 0),
      glm::vec2(0, 0),
      glm::vec2(-400, 0)
  );
  paddle.AddComponent<RigidBodyComponent>(
      100,
      20,
      glm::vec2((state.window.width / 2) - (100 / 2), state.window.height - 40),
      glm::vec2(0, 0)
  );
}

void App::OnInput(SDL_Event sdlEvent) {
  eventManager->eventBus->EmitEvent<KeyPressedEvent>(sdlEvent.key.keysym.sym);
}

void App::OnUpdate() {
  registry->GetSystem<KeyboardControlSystem>().SubscribeToEvents(eventManager->eventBus);
  registry->Update();
}

void App::OnRender() {
  registry->GetSystem<MovementSystem>().Update(time->deltaTime);
  registry->GetSystem<RenderRigidBodiesSystem>().Update(renderer->renderer);
}
