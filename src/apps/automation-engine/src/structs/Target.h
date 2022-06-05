#pragma once

#include <iostream>
#include <optional>
#include "DetectColorsArguments.h"
#include "ErodeDilateArguments.h"

struct Target {
  public:
    std::string tag;
    std::optional<DetectColorsArguments> detectColorsArguments;
    std::optional<ErodeDilateArguments> erodeDilateArguments;
};
