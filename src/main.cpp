#include "core/Loop.h"

class TimeImplement : public Time {
  public:
    double GetTicks() override {
      return 100;
    }
};

int main() {
  auto time = std::make_shared<TimeImplement>();

  Loop loop(time);
  loop.Run();

  return 0;
}
