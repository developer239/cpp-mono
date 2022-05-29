#pragma once


namespace Loop {
  struct Window {
    int width = 800;
    int height = 600;
  };

  struct State {
    bool isRunning = false;
    Window window;
  };
}
