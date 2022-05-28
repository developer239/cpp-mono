#include "Loop.h"

void Loop::Setup() const {
  renderer->Initialize();
}

void Loop::Run() {
  Setup();

  state.isRunning = true;
  while (state.isRunning) {
    ProcessInput();
    Update();
    Render();
  }
}

void Loop::ProcessInput() const {
  eventManager->HandleInput();
}

void Loop::Update() const {
  time->UpdateDeltaTime();
  time->UpdateMsPreviousFrame();

  eventManager->ResetEventBus();

  // game logic
}

void Loop::Render() {
  renderer->Render();
}