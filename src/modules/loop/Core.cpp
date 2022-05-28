#include "Core.h"

void Loop::Core::Setup() const {
  renderer->Initialize();
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

void Loop::Core::ProcessInput() const {
  eventManager->HandleInput();
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
