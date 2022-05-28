#include "Tick.h"

void Tick::UpdateDeltaTime() {
  deltaTime = (GetTicks() - msPreviousFrame) / 1000.0;
}

void Tick::UpdateMsPreviousFrame() {
  msPreviousFrame = GetTicks();
}
