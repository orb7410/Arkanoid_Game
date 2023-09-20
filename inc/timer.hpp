#pragma once
#include <chrono>

namespace arkanoid {
class Timer {
public:
    Timer() = default;
    Timer(Timer const& a_other) = default;
    Timer& operator=(Timer const& a_other) = default;
    ~Timer() = default;

    void start() noexcept;
    void stop() noexcept;
    double getTotalTimeInSeconds() const noexcept;
    double getTimeTillNow() const noexcept;
    
private:
    std::chrono::high_resolution_clock::time_point m_startTime;
    std::chrono::high_resolution_clock::time_point m_stopTime;
    bool m_isStarted = false;
};

} //arkanoid