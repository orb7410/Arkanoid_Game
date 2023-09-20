#include "timer.hpp"


namespace arkanoid {

void Timer::start() noexcept{
        m_startTime = std::chrono::high_resolution_clock::now();
        m_isStarted = true;
}
    
void Timer::stop() noexcept{
        m_stopTime = std::chrono::high_resolution_clock::now();
        m_isStarted = false;
}
    
double Timer::getTotalTimeInSeconds() const noexcept {
        std::chrono::duration<double> elapsed = m_stopTime - m_startTime;
        return elapsed.count();
}

double Timer::getTimeTillNow() const noexcept {
        if (false == m_isStarted) {
                return 0;
        }
        std::chrono::duration<double> time = std::chrono::high_resolution_clock::now() - m_startTime;
        return time.count();
}

} //arkanoid