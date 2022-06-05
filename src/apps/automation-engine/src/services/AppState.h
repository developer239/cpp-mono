#pragma once

#include <string>
#include <vector>
#include "../structs/Target.h"

class AppState {
  public:
    AppState() = default;

    int windowX = 0;
    int windowY = 0;

    std::vector<Target> targets;
};
