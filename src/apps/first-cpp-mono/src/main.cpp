#include "src/Core.h"
#include "src/Tick.implement.h"
#include "src/Renderer.implement.h"
#include "src/EventManager.implement.h"
#include "App.h"

int main() {
  auto time = std::make_shared<LoopSDL::TickImplement>();
  auto renderer = std::make_shared<LoopSDL::RendererImplement>();
  auto eventManager = std::make_shared<LoopSDL::EventManagerImplement>();

  auto app = std::make_shared<App>();

  Loop::Core loop(time, renderer, eventManager, app);
  loop.Run();

  return 0;
}
