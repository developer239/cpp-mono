#pragma once

#include <iostream>
#include <optional>

struct DetectColorsArguments {
  // TODO: use vector instead
  int lowerRed = 0;
  int lowerGreen = 0;
  int lowerBlue = 0;

  // TODO: use vector instead
  int upperRed = 0;
  int upperGreen = 0;
  int upperBlue = 0;

  // TODO: use vector instead
  int minWidth = 0;
  int minHeight = 0;
};

struct ErodeDilateArguments {
  int morphologyWidth = 0;
  int morphologyHeight = 0;
};

struct Target {
  public:
    std::string tag;
    std::optional<DetectColorsArguments> detectColorsArguments;
    std::optional<ErodeDilateArguments> erodeDilateArguments;
};
