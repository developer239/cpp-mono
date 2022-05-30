#pragma once

#include "Core.structs.h"

namespace Loop {
  class IRenderable {
    public:
      virtual void OnRender(State& state) = 0;
  };
}
