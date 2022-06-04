#pragma once

#include <string>

class Keyboard {
  public:
    static void Type(std::string query);

    static void Click(char keyASCII);

    static void ClickEnter();

    static void ArrowUp();

    static void ArrowDown();

    static void ArrowLeft();

    static void ArrowRight();

    static void Press(int key);

    static void Release(int key);

    static int MapASCIIToVirtualKey(char key);
};
