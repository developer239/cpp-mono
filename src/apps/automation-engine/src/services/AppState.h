#pragma once

#include <string>
#include <vector>

struct Action {
  std::string areaType;

  unsigned int lastAt;
};

// TODO: All of this should probably live in Lua

class AppState {
  public:
    AppState() = default;

    int windowX = 0;
    int windowY = 60;

    int lowerRed = 0;
    int lowerGreen = 0;
    int lowerBlue = 105;

    int upperRed = 200;
    int upperGreen = 65;
    int upperBlue = 255;

    int morphologyWidth = 10;
    int morphologyHeight = 10;

    bool shouldDrawBoundingBoxes = true;
    bool shouldDetectColors = true;
    bool shouldErodeDilate = true;
    bool shouldFindContours = true;


    int lastActionTopAt = 0;
    int lastActionMidAt = 0;
    int lastActionBottomAt = 0;

    std::vector<Action> actions{
        { "AreaTop",    0 },
        { "AreaMid",    0 },
        { "AreaBottom", 0 }
    };
};
