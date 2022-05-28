#ifndef LOOP_H
#define LOOP_H

#include <iostream>
#include "Time.h"
#include "Loop.structs.h"

template<class GetTicksStrategy>
  class Loop {
    public:
      Time<GetTicksStrategy> time;
      LoopState state;

      Loop();

      ~Loop();

      void Setup();

      void Run();

      void ProcessInput();

      void Update();

      void Render();
  };

template<class GetTicksStrategy>
  Loop<GetTicksStrategy>::Loop() {
    time = Time<GetTicksStrategy>();
  }

template<class GetTicksStrategy>
  Loop<GetTicksStrategy>::~Loop() = default;

template<class GetTicksStrategy>
  void Loop<GetTicksStrategy>::Setup() {
  }

template<class GetTicksStrategy>
  void Loop<GetTicksStrategy>::Run() {
    Setup();

    while (state.isRunning) {
      ProcessInput();
      Update();
      Render();
    }
  }

template<class GetTicksStrategy>
  void Loop<GetTicksStrategy>::ProcessInput() {
  }

template<class GetTicksStrategy>
  void Loop<GetTicksStrategy>::Update() {
    time.UpdateDeltaTime();
    time.UpdateMsPreviousFrame();

    // game logic
  }

template<class GetTicksStrategy>
  void Loop<GetTicksStrategy>::Render() {
  }

#endif
