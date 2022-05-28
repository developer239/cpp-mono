#include <iostream>
#include "./Loop.h"

Loop::Loop() {
  std::cout << "Loop constructor called" << std::endl;
}

Loop::~Loop() {
  std::cout << "Loop destructor called" << std::endl;
}

void Loop::ProcessInput() {
}

void Loop::Setup() {
}

void Loop::Update() {
  std::cout << "Loop update" << std::endl;
}

void Loop::Render() {
  std::cout << "Loop render" << std::endl;
}

void Loop::Run() {
  Setup();

  while (state.isRunning) {
    ProcessInput();
    Update();
    Render();
  }
}

void Loop::Destroy() {

}
