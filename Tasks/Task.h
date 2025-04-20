#pragma once

class Task {
 public:
    Task();
    Task(const Task& task);

    virtual ~Task() = default;
    virtual void Init() = 0;
};
