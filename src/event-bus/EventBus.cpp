#include "EventBus.h"

HandlerList* EventBus::GetList(std::type_index type) {
  return subscribers[type].get();
}

bool EventBus::ShouldCreateList(std::type_index type) {
  return !GetList(type);
}

void EventBus::CreateList(std::type_index type) {
  subscribers[type] = std::make_unique<HandlerList>();
}

void EventBus::AddItem(std::type_index type, std::unique_ptr<IEventCallback> subscriber) {
  subscribers[type]->push_back(std::move(subscriber));
}

void EventBus::Reset() {
  subscribers.clear();
}
