#include "Loop.h"

void Loop::Setup() {
}

void Loop::Run() {
  Setup();

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

  std::cout << std::to_string(time->msPreviousFrame) << std::endl;

  // game logic
}

void Loop::Render() {
}
