#pragma once

#include <ApplicationServices/ApplicationServices.h>

class Mouse {
  public:
    static void move(float x, float y);

    static void click(CGMouseButton button, bool shouldPress);

    static CGPoint getLocation();

  private:
    static void executeEvent(CGMouseButton button, CGEventType type, CGPoint location);
};
