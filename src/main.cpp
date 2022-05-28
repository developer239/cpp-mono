#include "core/Loop.h"
#include "event-bus/EventBus.h"
#include "core-sdl-implement/TimeImplement.h"
#include "core-sdl-implement/RendererImplement.h"
#include "core-sdl-implement/EventManagerImplement.h"

int main() {
  auto time = std::make_shared<TimeImplement>();
  auto renderer = std::make_shared<RendererImplement>();
  auto eventManager = std::make_shared<EventManagerImplement>();

  Loop loop(time, renderer, eventManager);
  loop.Run();

  return 0;
}
