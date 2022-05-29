#pragma once

namespace Loop {
  class IApp {
    public:
      virtual void Setup() = 0;

      virtual void OnInput() = 0;

      virtual void OnUpdate() = 0;

      virtual void OnRender() = 0;
  };
}
