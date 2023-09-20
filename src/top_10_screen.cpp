#include "top_10_screen.hpp"
#include <fstream>

namespace arkanoid {
namespace {
void sortVec(std::vector<Winner>& a_top10) {
    auto cmp = [](const Winner& first, const Winner& sec) {
        if (first.getScore() != sec.getScore()) {
            return first.getScore() > sec.getScore();
        } 
        else {
            return first.getTime() < sec.getTime();
        }
    };
    std::sort(a_top10.begin(), a_top10.end(), cmp);
}
} //namespace

Top10Screen::Top10Screen(sf::Vector2f a_size, sf::RenderWindow& a_window)
: m_window(a_window)
, m_board(a_size)
, m_font("../static/Alkatra-Regular.ttf")
, m_fileName(std::string("../static/top10.dat"))
, m_top10()
, m_title("TOP 10 WITH THE HIGHEST SCORE:", m_font, sf::Vector2f(m_board.getBoard().getPosition().x + m_board.getBoard().getSize().x / 4.5, 
                m_board.getBoard().getPosition().y + m_board.getBoard().getSize().y / 10), 45, sf::Color::Black)  
{
    std::fstream file(m_fileName, std::ios::in);
    if (!file) {
        file.open(m_fileName, std::ios::out);
        file.close();
    } else {
        std::string name;
        size_t score;
        double time;
        while (file >> name >> score >> time && m_top10.size() < 11) {
            m_top10.push_back(Winner(name, score, time));
        }
        file.close();
        sortVec(m_top10);
    }
}

void Top10Screen::drawTexts(sf::Vector2f a_top10Pos) 
{
    for (size_t i = 0; i < m_top10.size(); ++i) {
        sf::Text text(m_top10[i].getName() + "         " + std::to_string(m_top10[i].getScore()) + "       " + std::to_string(m_top10[i].getTime()).substr(0, 5), m_font.get(), 40);
        text.setFillColor(sf::Color::Black);
        text.setStyle(sf::Text::Bold);
        text.setPosition(a_top10Pos.x + 150, a_top10Pos.y + (i * 40));
        m_window.draw(text);
    }
}

std::optional<std::tuple<bool, size_t, double, std::string>> Top10Screen::run()
{
    sf::Event event;
    while (m_window.isOpen()) {
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                m_window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
                    if (m_board.getBounding().contains(mousePos.x, mousePos.y)) {
                        return std::make_tuple(false, 0, 0, "");
                    }
                }
            } else if (event.type == sf::Event::KeyPressed) {
                return std::make_tuple(false, 0, 0, "");
            }
        }
        drawScreen();
    }
    return std::make_tuple(false, 0, 0, "");
}

void Top10Screen::drawScreen() 
{
    sf::Vector2f top10Pos(m_title.getPosition().x,m_title.getPosition().y + 120);
    m_window.clear();
    m_window.draw(m_board.getBoard());
    m_title.draw(m_window);
    drawTexts(top10Pos);
    m_window.display();
}

std::vector<Winner> const& Top10Screen::getTop10() noexcept 
{
    return m_top10;
}

void Top10Screen::loadTop10ToFile() const noexcept 
{
    std::ofstream file(m_fileName);
    if (file) {
        for (size_t i = 0; i < m_top10.size(); ++i) {
            file << m_top10[i].getName() << ' '
                 << m_top10[i].getScore() << ' '
                 << m_top10[i].getTime() << '\n';
        }
        file.close();
    } 
    else {
        std::cerr << "Error: Could not open file " << m_fileName ;
    }
}

void Top10Screen::addToTop10(Winner a_winner) noexcept 
{
    if (checkIfTop10(a_winner)) {
        m_top10.push_back(a_winner);
        sortVec(m_top10);
        if (m_top10.size() > 10) {
            m_top10.erase(m_top10.begin() + 10, m_top10.end());
        }
        loadTop10ToFile();
    }
}

bool Top10Screen::checkIfTop10(Winner a_winner) const noexcept 
{
    if (m_top10.size() < 10) {
        return true;
    }
    for (size_t i = 0; i < m_top10.size(); ++i) {
        if (a_winner > m_top10[i]) {
            return true;
        }
    }
    return false;
}
} //arkanoid