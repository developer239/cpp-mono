#include <iostream>
#include <SDL.h>

#include "EventManager.implement.h"

void
LoopSDL::EventManagerImplement::HandleInput(Loop::State& state, const std::shared_ptr<Loop::EventManager>& eventManager) {
  SDL_Event sdlEvent;

  while (SDL_PollEvent(&sdlEvent)) {
    switch (sdlEvent.type) {
      case SDL_QUIT:
        state.isRunning = false;
        break;
      case SDL_KEYDOWN:
        if (sdlEvent.key.keysym.sym == SDLK_ESCAPE) {
          state.isRunning = false;
        }
        break;
    }
  }
}
