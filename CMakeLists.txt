cmake_minimum_required(VERSION 3.22)
project(cpp_mono)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_mono
        src/main.cpp
        src/core/Loop.h
        src/core/Loop.cpp
        src/core/Tick.h
        src/core/Tick.cpp
        src/core/Renderer.h
        src/core-sdl-implement/Tick.implement.cpp
        src/core-sdl-implement/Tick.implement.h
        src/core-sdl-implement/Renderer.implement.cpp
        src/core-sdl-implement/Renderer.implement.h
        src/event-bus/Event.h
        src/event-bus/EventBus.h
        src/core/EventManager.cpp
        src/core/EventManager.h
        src/core-sdl-implement/EventManager.implement.cpp src/core-sdl-implement/EventManager.implement.h)
