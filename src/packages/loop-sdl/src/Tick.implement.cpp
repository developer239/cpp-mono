#include <SDL.h>
#include "Tick.implement.h"

double LoopSDL::TickImplement::GetTicks() {
  return SDL_GetTicks();
}
