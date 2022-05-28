#include "core/Loop.h"

struct GetTicksStrategy {
  static double GetTicks() {
    std::cout << "GetTicks GetTicks GetTicks" << std::endl;
    return 0;
  }
};

int main() {
  Loop<GetTicksStrategy> loop;
  loop.Run();

  return 0;
}
