#pragma once

class Task {
    public:
        Task();
        Task(const Task& task);

        virtual void Init() = 0;
};
