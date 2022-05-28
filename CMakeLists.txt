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
        src/core-sdl-implement/TimeImplement.cpp
        src/core-sdl-implement/TimeImplement.h
        src/core-sdl-implement/RendererImplement.cpp
        src/core-sdl-implement/RendererImplement.h
        src/event-bus/Event.h
        src/event-bus/EventBus.h
        )
