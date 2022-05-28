#pragma once

class Renderer {
  public:
    virtual void Initialize() = 0;

    virtual void Render() = 0;
};