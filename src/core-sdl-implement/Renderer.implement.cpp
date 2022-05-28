#include "Renderer.implement.h"

void RendererImplement::Initialize() {
  std::cout << "Renderer initialized" << std::endl;
}

void RendererImplement::Render() {
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::cout << "Rendering" << std::endl;
}
