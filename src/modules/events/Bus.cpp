#include "Bus.h"

Events::HandlerList* Events::Bus::GetList(std::type_index type) {
  return subscribers[type].get();
}

bool Events::Bus::ShouldCreateList(std::type_index type) {
  return !GetList(type);
}

void Events::Bus::CreateList(std::type_index type) {
  subscribers[type] = std::make_unique<HandlerList>();
}

void Events::Bus::AddItem(std::type_index type, std::unique_ptr<IEventCallback> subscriber) {
  subscribers[type]->push_back(std::move(subscriber));
}

void Events::Bus::Reset() {
  subscribers.clear();
}
