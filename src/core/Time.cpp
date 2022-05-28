#include "Time.h"

void Time::UpdateDeltaTime() {
  deltaTime = (GetTicks() - msPreviousFrame) / 1000.0;
}

void Time::UpdateMsPreviousFrame() {
  msPreviousFrame = GetTicks();
}
