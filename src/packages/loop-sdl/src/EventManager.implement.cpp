#include <iostream>
#include <SDL.h>

#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "EventManager.implement.h"

void
LoopSDL::EventManagerImplement::HandleInput(
    Loop::State& state, Loop::IApp* appInstance, void (Loop::IApp::* OnInput)(int32_t keyCode)
) {
  SDL_Event sdlEvent;

  while (SDL_PollEvent(&sdlEvent)) {
    ImGui_ImplSDL2_ProcessEvent(&sdlEvent);
    ImGuiIO& io = ImGui::GetIO();

    int mouseX, mouseY;
    const int buttons = SDL_GetMouseState(&mouseX, &mouseY);

    io.MousePos = ImVec2(mouseX, mouseY);
    io.MouseDown[0] = buttons & SDL_BUTTON(SDL_BUTTON_LEFT);
    io.MouseDown[1] = buttons & SDL_BUTTON(SDL_BUTTON_RIGHT);

    switch (sdlEvent.type) {
      case SDL_QUIT:
        state.isRunning = false;
        break;
      case SDL_KEYDOWN:
        if (sdlEvent.key.keysym.sym == SDLK_ESCAPE) {
          state.isRunning = false;
        }

        (appInstance->*OnInput)(sdlEvent.key.keysym.sym);
        break;
    }
  }
}
