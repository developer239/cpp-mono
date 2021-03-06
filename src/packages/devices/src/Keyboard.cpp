#include <ApplicationServices/ApplicationServices.h>
#include "Delay.h"
#include "Keyboard.h"

void Keyboard::Type(std::string query) {
  for (std::string::size_type i = 0; i < query.size(); i += 1) {
    Click(query[i]);
  }
}

void Keyboard::Click(char keyASCII) {
  int key = MapASCIIToVirtualKey(keyASCII);

  Press(key);
  Release(key);
}

void Keyboard::ClickEnter() {
  Press(36);
  Release(36);
}

void Keyboard::ArrowUp() {
  Press(126);
  Release(126);
}

void Keyboard::ArrowDown() {
  Press(125);
  Release(125);
}

void Keyboard::ArrowLeft() {
  Press(123);
  Release(123);
}

void Keyboard::ArrowRight() {
  Press(124);
  Release(124);
}

void Keyboard::Press(int key) {
  CGEventSourceRef source = CGEventSourceCreate(kCGEventSourceStateHIDSystemState);
  CGEventRef event = CGEventCreateKeyboardEvent(source, (CGKeyCode) key, true);
  CGEventPost(kCGHIDEventTap, event);

  CFRelease(event);
  CFRelease(source);

  delay(5);
}

void Keyboard::Release(int key) {
  CGEventSourceRef source = CGEventSourceCreate(kCGEventSourceStateHIDSystemState);
  CGEventRef event = CGEventCreateKeyboardEvent(source, (CGKeyCode) key, false);

  CGEventPost(kCGHIDEventTap, event);
  CFRelease(event);
  CFRelease(source);

  delay(5);
}

int Keyboard::MapASCIIToVirtualKey(char key) {
  switch (key) {
    case 'a':
      return 0;
    case 's':
      return 1;
    case 'd':
      return 2;
    case 'f':
      return 3;
    case 'h':
      return 4;
    case 'g':
      return 5;
    case 'z':
      return 6;
    case 'x':
      return 7;
    case 'c':
      return 8;
    case 'v':
      return 9;
    case 'b':
      return 11;
    case 'q':
      return 12;
    case 'w':
      return 13;
    case 'e':
      return 14;
    case 'r':
      return 15;
    case 'y':
      return 16;
    case 't':
      return 17;
    case '1':
      return 18;
    case '2':
      return 19;
    case '3':
      return 20;
    case '4':
      return 21;
    case '6':
      return 22;
    case '5':
      return 23;
    case '=':
      return 24;
    case '9':
      return 25;
    case '7':
      return 26;
    case '-':
      return 27;
    case '8':
      return 28;
    case '0':
      return 29;
    case ')':
      return 30;
    case 'o':
      return 31;
    case 'u':
      return 32;
    case '(':
      return 33;
    case 'i':
      return 34;
    case 'p':
      return 35;
    case 'l':
      return 37;
    case 'j':
      return 38;
    case '\'':
      return 39;
    case 'k':
      return 40;
    case ';':
      return 41;
    case '\\':
      return 42;
    case ',':
      return 43;
    case '/':
      return 44;
    case 'n':
      return 45;
    case 'm':
      return 46;
    case '.':
      return 47;
    case ' ':
      return 49;
    case '`':
      return 50;
    default:
      return 99;
  }
}
