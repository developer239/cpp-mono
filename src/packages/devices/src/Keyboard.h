#pragma once

#include <string>

class Keyboard {
  public:
    static void type(std::string query);

    static void click(char keyASCII);

    static void clickEnter();

    static void arrowUp();

    static void arrowDown();

    static void arrowLeft();

    static void arrowRight();

    static void press(int key);

    static void release(int key);

    static int mapASCIIToVirtualKey(char key);
};
