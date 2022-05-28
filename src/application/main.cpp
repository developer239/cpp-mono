#include "../core/Loop.h"
#include "../event-bus/EventBus.h"
#include "../core-sdl-implement/Tick.implement.h"
#include "../core-sdl-implement/Renderer.implement.h"
#include "../core-sdl-implement/EventManager.implement.h"

int main() {
  auto time = std::make_shared<TickImplement>();
  auto renderer = std::make_shared<RendererImplement>();
  auto eventManager = std::make_shared<EventManagerImplement>();

  Loop loop(time, renderer, eventManager);
  loop.Run();

  return 0;
}
