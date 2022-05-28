#include "Loop.h"

void Loop::Setup() {
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

void Loop::ProcessInput() {
}

void Loop::Update() const {
  time->UpdateDeltaTime();
  time->UpdateMsPreviousFrame();

  // game logic
}

void Loop::Render() {
}
