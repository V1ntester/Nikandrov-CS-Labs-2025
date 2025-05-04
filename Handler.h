#pragma once

class Handler {
 public:
    Handler(bool isInteractive = true);

    ~Handler();

    void Init();

 private:
    bool isInteractive = false;

    void InteractiveModeInit();
    void DemoModeInit();
};
