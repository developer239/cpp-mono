#include <thread>
#include "core/Loop.h"
#include "core-sdl-implement/TimeImplement.h"
#include "core-sdl-implement/RendererImplement.h"

int main() {
  auto time = std::make_shared<TimeImplement>();
  auto renderer = std::make_shared<RendererImplement>();

  Loop loop(time, renderer);
  loop.Run();

  return 0;
}
