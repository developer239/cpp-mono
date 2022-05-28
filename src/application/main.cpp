#include "Loop.h"
#include "Tick.implement.h"
#include "Renderer.implement.h"
#include "EventManager.implement.h"

int main() {
  auto time = std::make_shared<TickImplement>();
  auto renderer = std::make_shared<RendererImplement>();
  auto eventManager = std::make_shared<EventManagerImplement>();

  Loop loop(time, renderer, eventManager);
  loop.Run();

  return 0;
}
