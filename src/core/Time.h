#ifndef CORE_H
#define CORE_H

template<class GetTicksStrategy>
  class Time {
    public:
      double msPreviousFrame = 0;
      double deltaTime = 0;

      void updateDeltaTime();

      void updateMsPreviousFrame();

      double GetTicks();
  };

template<class GetTicksStrategy>
  void Time<GetTicksStrategy>::updateDeltaTime() {
    deltaTime = (GetTicks() - msPreviousFrame) / 1000.0;
  }

template<class GetTicksStrategy>
  void Time<GetTicksStrategy>::updateMsPreviousFrame() {
    msPreviousFrame = GetTicks();
  }

template<class GetTicksStrategy>
  double Time<GetTicksStrategy>::GetTicks() {
    return GetTicksStrategy::GetTicks();
  }

#endif
