#pragma once
#include <SFML/Graphics.hpp>
#include <tuple> 
#include <optional> 

namespace arkanoid {

class Screen {
public:
    virtual ~Screen() = default;

    virtual std::optional<std::tuple<bool, size_t, double, std::string>> run() = 0;
};

} //arkanoid
