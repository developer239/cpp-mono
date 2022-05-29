#include "Core.h"

void Loop::Core::Setup() {
  renderer->Initialize(state.window.width, state.window.height);
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
  eventManager->HandleInput(state, eventManager);
}

void Loop::Core::Update() const {
  time->UpdateDeltaTime();
  time->UpdateMsPreviousFrame();

  eventManager->ResetEventBus();

  // game logic
}

void Loop::Core::Render() {
  renderer->Render();
}