#pragma once

class ScreenSystem : public System {
  public:
    ScreenSystem() = default;

    void Update(Screen* screen) {
      screen->Screenshot();
    }
};
