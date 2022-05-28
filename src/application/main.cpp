#include "../core/Loop.h"
#include "../event-bus/EventBus.h"
#include "../implements/core-sdl/Tick.implement.h"
#include "../implements/core-sdl/Renderer.implement.h"
#include "../implements/core-sdl/EventManager.implement.h"

int main() {
  auto time = std::make_shared<TickImplement>();
  auto renderer = std::make_shared<RendererImplement>();
  auto eventManager = std::make_shared<EventManagerImplement>();

  Loop loop(time, renderer, eventManager);
  loop.Run();

  return 0;
}
