#pragma once

class Tick {
  public:
    double msPreviousFrame = 0;

    double deltaTime = 0;

    void UpdateDeltaTime();

    void UpdateMsPreviousFrame();

    virtual double GetTicks() = 0;
};
