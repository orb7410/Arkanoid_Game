#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>

namespace arkanoid {
    
class Winner {
public:
    Winner() = default;
    explicit Winner(std::string a_name, size_t a_score, double a_time);
    Winner(Winner const& a_other) = default;
    Winner& operator=(Winner const& a_other) = default;
    ~Winner() = default;

    bool operator>(Winner const& a_other) noexcept;
    bool operator<(Winner const& a_other) noexcept;
    // bool operator<=(Winner const& a_other) noexcept;
    // bool operator>=(Winner const& a_other) noexcept;
    bool operator==(Winner const& a_other) const noexcept;
    // bool operator!=(Winner const& a_other) noexcept;
    
    double getTime() const noexcept;
    size_t getScore() const noexcept;
    const std::string& getName() const noexcept; 

private:
    std::string m_name;
    size_t m_score;
    double m_time;
};

} //arkanoid
