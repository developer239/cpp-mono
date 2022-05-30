#include "Core.h"

Loop::Core::Core(
    std::shared_ptr<Tick> time, std::shared_ptr<Renderer> renderer, std::shared_ptr<EventManager> eventManager,
    std::shared_ptr<IApp> app
) :
    time(std::move(time)),
    eventManager(std::move(eventManager)) {
  this->renderer = std::move(renderer);
  this->renderer->state = &this->state;

  this->app = std::move(app);
  this->app->eventBus = this->eventManager->eventBus;
}

void Loop::Core::Setup() {
  renderer->Initialize(state.window.width, state.window.height);
  app->Setup();
}

void Loop::Core::Run() {
  Setup();

  state.isRunning = true;
  while (state.isRunning) {
    ProcessInput();
    Update();
    Render();
  }
}

void Loop::Core::ProcessInput() {
  eventManager->HandleInput(state, app.get(), &IApp::OnInput);
}

void Loop::Core::Update() const {
  time->UpdateDeltaTime();
  time->UpdateMsPreviousFrame();

  eventManager->ResetEventBus();

  app->OnUpdate();
}

void Loop::Core::Render() {
  renderer->Render(app.get(), &IRenderable::OnRender);
}
