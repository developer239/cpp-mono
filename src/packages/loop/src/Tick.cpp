#include "Tick.h"

void Loop::Tick::UpdateDeltaTime() {
  deltaTime = (GetTicks() - msPreviousFrame) / 1000.0;
}

void Loop::Tick::UpdateMsPreviousFrame() {
  msPreviousFrame = GetTicks();
}
