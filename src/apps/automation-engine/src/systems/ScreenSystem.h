#pragma once

class ScreenSystem : public System {
  public:
    ScreenSystem() = default;

    void Update(std::unique_ptr<Screen>& screen) {
      screen->Screenshot();
    }
};
