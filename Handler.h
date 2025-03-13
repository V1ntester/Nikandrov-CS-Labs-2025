#pragma once

class Handler {
 private:
    bool isInteractive = false;

    void InteractiveModeInit();
    void DemoModeInit();

 public:
    Handler(bool isInteractive = true);

    ~Handler();

    void Init();
};
