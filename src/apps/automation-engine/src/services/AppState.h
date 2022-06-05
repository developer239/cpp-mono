#pragma once

#include <string>
#include <vector>
#include "../structs/Target.h"

struct Action {
  std::string areaType;

  unsigned int lastAt;
};

class AppState {
  public:
    AppState() = default;

    int windowX = 0;
    int windowY = 0;

    std::vector<Target> targets;

    std::vector<Action> actions{
        { "AreaTop",    0 },
        { "AreaMid",    0 },
        { "AreaBottom", 0 },
        { "AreaBack",   0 }
    };
};
