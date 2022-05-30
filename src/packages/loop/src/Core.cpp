#include "Core.h"

#include <utility>

Loop::Core::Core(
    std::shared_ptr<Tick> time, std::shared_ptr<Renderer> renderer, std::shared_ptr<EventManager> eventManager
) {
  this->time = std::move(time);
  this->renderer = std::move(renderer);
  this->eventManager = std::move(eventManager);
}

void Loop::Core::Setup() {
  renderer->Initialize(state.window.width, state.window.height);
  OnSetup();
}

void Loop::Core::Run() {
  Setup();

  state.isRunning = true;
  while (state.isRunning) {
    ProcessInput();
    Update();
    Render();
  }
}

void Loop::Core::ProcessInput() {
  auto sdlEvent = eventManager->HandleInput(state);
  if (sdlEvent.key.keysym.sym != 0) {
    OnInput(sdlEvent);
  }
}

void Loop::Core::Update() {
  time->UpdateDeltaTime();
  time->UpdateMsPreviousFrame();

  eventManager->ResetEventBus();

  OnUpdate();
}

void Loop::Core::Render() {
  renderer->RenderStart();
  OnRender();
  renderer->RenderEnd();
}
