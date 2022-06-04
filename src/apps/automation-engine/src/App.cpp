#include <SDL.h>
#include "App.h"

#include "systems/ScreenSystem.h"
#include "systems/RenderScreenSystem.h"

void App::OnSetup() {
  screen = new Screen(&state.window.width, &state.window.height, &appState.windowX, &appState.windowY);

  registry->AddSystem<ScreenSystem>();
  registry->AddSystem<RenderScreenSystem>();
}

void App::OnInput(SDL_Event event) {

}

void App::OnUpdate() {
  registry->GetSystem<ScreenSystem>().Update(screen);
}

void App::OnRender() {
  registry->GetSystem<RenderScreenSystem>().Update(renderer->renderer, screen, &appState);
}
