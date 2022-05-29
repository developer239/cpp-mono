#include "EventManager.h"

void Loop::EventManager::ResetEventBus() const {
  eventBus->Reset();
}

Loop::EventManager::EventManager() {
  eventBus = std::make_unique<Events::Bus>();
}
