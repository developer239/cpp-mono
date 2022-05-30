#include <SDL_ttf.h>
#include "imgui.h"
#include "imgui_sdl.h"
#include "Renderer.implement.h"
#include "src/Logger.h"

void LoopSDL::RendererImplement::Initialize(int& width, int& height) {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    Logger::Err("Error initializing SDL.");
    return;
  }

  if (TTF_Init() != 0) {
    Logger::Err("Error initializing SDL TTF.");
    return;
  }

  SDL_GetCurrentDisplayMode(0, &displayMode);

  window = SDL_CreateWindow(
      nullptr,
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      width,
      height,
      0
  );

  if (!window) {
    Logger::Err("Error creating SDL window.");
    return;
  }

  renderer = SDL_CreateRenderer(window, -1, 0);
  if (!renderer) {
    Logger::Err("Error creating SDL renderer.");
    return;
  }

  ImGui::CreateContext();
  ImGuiSDL::Initialize(renderer, width, height);
}

void LoopSDL::RendererImplement::Render(
    Loop::IRenderable* appInstance, void (Loop::IRenderable::* OnRender)(Loop::State& state)) {
  SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
  SDL_RenderClear(renderer);

  (appInstance->*OnRender)(*state);

  ImGui::NewFrame();
  ImGui::ShowDemoWindow();
  ImGui::Render();
  ImGuiSDL::Render(ImGui::GetDrawData());

  SDL_RenderPresent(renderer);
}

LoopSDL::RendererImplement::~RendererImplement() {
  ImGuiSDL::Deinitialize();
  ImGui::DestroyContext();

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
