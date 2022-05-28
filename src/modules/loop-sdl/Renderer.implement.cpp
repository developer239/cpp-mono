#include "Renderer.implement.h"

void LoopSDL::RendererImplement::Initialize() {
  std::cout << "Renderer initialized" << std::endl;
}

void LoopSDL::RendererImplement::Render() {
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::cout << "Rendering" << std::endl;
}
