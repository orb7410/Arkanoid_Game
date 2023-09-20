#include "top_10_screen.hpp"
#include "winner.hpp"

namespace arkanoid {

Winner::Winner(std::string a_name, size_t a_score, double a_time)
: m_name(a_name)
, m_score(a_score)
, m_time(a_time) {
}

const std::string& Winner::getName() const noexcept {
    return m_name;
}

size_t Winner::getScore() const noexcept {
    return m_score;
}

double Winner::getTime() const noexcept {
    return m_time;
}

bool Winner::operator<(Winner const& a_other) noexcept {
    if (m_score < a_other.m_score) {
        return true;
    } 
    else if (m_score == a_other.m_score) {
        return m_time < a_other.m_time;
    } 
    else {
        return false;
    }
}

bool Winner::operator>(Winner const& a_other) noexcept {
    if (m_score > a_other.m_score) {
        return true;
    } 
    else if (m_score == a_other.m_score) {
        return m_time > a_other.m_time;
    } 
    else {
        return false;
    }
}

// bool Winner::operator<=(Winner const& a_other) noexcept {
//     return !(m_score > a_other.m_score);
// }

// bool Winner::operator>=(Winner const& a_other) noexcept {
//     return !(this < a_other);
// }

bool Winner::operator==(Winner const& a_other) const noexcept {
    return (m_score == a_other.m_score && m_name == a_other.m_name && m_time == a_other.m_time);
}

// bool Winner::operator!=(Winner const& a_other) noexcept {
//     return !(this == a_other);
// }

} //arkanoid