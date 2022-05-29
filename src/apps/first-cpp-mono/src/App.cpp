#include "App.h"
#include "src/Logger.h"

void App::Setup() {
  Logger::Log("App::Setup()");
}

void App::OnUpdate() {
  Logger::Log("App::OnUpdate()");
}

void App::OnRender() {
  Logger::Log("App::OnRender()");
}
