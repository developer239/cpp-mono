#ifndef CORE_H
#define CORE_H

struct LoopState {
  bool isRunning = true;
};

class Loop {
  private:

  public:
    LoopState state;

    Loop();

    ~Loop();

    void Setup();

    void Run();

    void ProcessInput();

    void Update();

    void Render();

    void Destroy();
};

#endif
