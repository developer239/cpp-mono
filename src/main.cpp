#include "core/Loop.h"
#include "event-bus/EventBus.h"
#include "core-sdl-implement/TimeImplement.h"
#include "core-sdl-implement/RendererImplement.h"

class KeyPressedEvent : public EventBase {
  public:
    std::string symbol;

    explicit KeyPressedEvent(std::string& symbol) : symbol(symbol) {
    }
};

class KeyboardControlSystem {
  public:
    void SubscribeToEvents(std::unique_ptr<EventBus>& eventBus) {
      eventBus->SubscribeToEvent<KeyPressedEvent>(this, &KeyboardControlSystem::OnKeyPressed);
    }

    void OnKeyPressed(KeyPressedEvent& event) {
      std::cout << "KeyboardControlSystem: " << event.symbol << " pressed" << std::endl;
    }
};

int main() {
  auto time = std::make_shared<TimeImplement>();
  auto renderer = std::make_shared<RendererImplement>();

  auto eventBus = std::make_unique<EventBus>();

  auto keyboardControlSystem = KeyboardControlSystem();
  keyboardControlSystem.SubscribeToEvents(eventBus);

  std::string input = "some input";

  eventBus->EmitEvent<KeyPressedEvent>(input);

  Loop loop(time, renderer);
  loop.Run();

  return 0;
}
