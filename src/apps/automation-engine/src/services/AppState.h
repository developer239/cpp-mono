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
    int windowY = 60;

    std::vector<Target> targets{
        Target{
            "Apple",
            DetectColorsArguments{
                0,
                0,
                105,
                200,
                65,
                255,
                22,
                22,
            },
            ErodeDilateArguments{ 10, 10 }
        },
        Target{
            "Star",
            DetectColorsArguments{
                0,
                135,
                105,
                75,
                255,
                255,
                15,
                15
            },
            ErodeDilateArguments{ 10, 10 }
        }
    };

    std::vector<Action> actions{
        { "AreaTop",    0 },
        { "AreaMid",    0 },
        { "AreaBottom", 0 },
        { "AreaBack", 0 }
    };
};
