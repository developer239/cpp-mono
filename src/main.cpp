#include <thread>
#include "core/Loop.h"

class TimeImplement : public Time {
  public:
    double GetTicks() override {
      return 100;
    }
};

class RendererImplement : public Renderer {
  public:
    void Initialize() override {
      std::cout << "Renderer initialized" << std::endl;
    }

    void Render() override {
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
      std::cout << "Rendering" << std::endl;
    }
};

int main() {
  auto time = std::make_shared<TimeImplement>();
  auto renderer = std::make_shared<RendererImplement>();

  Loop loop(time, renderer);
  loop.Run();

  return 0;
}
