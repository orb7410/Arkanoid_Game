#include "input_screen.hpp"


namespace arkanoid {
namespace {

bool checkIfDirty(bool& a_isDirty, std::string const& a_input)
{
	if (!a_input.empty()) {
		a_isDirty = true;
		return true;
	}
	a_isDirty = false;
	return false;
}
} //namespace

InputScreen::InputScreen(sf::Vector2f a_size, sf::RenderWindow& a_window)
: m_window(a_window)
, m_font{"../static/Alkatra-Regular.ttf"}
, m_board{a_size}
, m_text{"", m_font.get()}
, m_input{}
, m_title{"congrats! you're in the top 10! please enter your name", m_font, sf::Vector2f(m_window.getSize().x / 10.50f, m_window.getSize().y / 4.5f), 45, sf::Color::Black}
, m_textBox{sf::Vector2f(m_board.getBoard().getSize().x * 0.4f, m_board.getBoard().getSize().y * 0.15f)}
{
	m_textBox.setFillColor(sf::Color::White);
    m_textBox.setOutlineThickness(2.f);
    m_textBox.setOutlineColor(sf::Color::Black);
    m_textBox.setOrigin(m_textBox.getLocalBounds().width / 2, m_textBox.getLocalBounds().height / 2);
    m_textBox.setPosition(m_board.getBoard().getPosition().x + m_board.getBoard().getSize().x / 2,
                 m_board.getBoard().getPosition().y + m_board.getBoard().getSize().y / 2 );
    m_text.setPosition(m_textBox.getPosition().x - m_textBox.getSize().x / 2.5 , m_textBox.getPosition().y - m_textBox.getSize().y /2);
	m_text.setFillColor(sf::Color::Black);
    m_text.setCharacterSize(60);
}


std::optional<std::tuple<bool, size_t, double, std::string>> InputScreen::run()
{
	while (m_window.isOpen()) {
        if (drawScreen()){
			return std::make_tuple(false, 0, 0.0, getInput());
		}
    }
	return std::make_tuple(false, 0, 0.0, getInput());
}

bool InputScreen::drawScreen() 
{
    sf::Event event;

	bool end = false;
	bool text_dirty = false;
	while (m_window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			// return a status from this function
			m_window.close();
		}
		if (event.type == sf::Event::TextEntered) {
			if (std::isprint(event.text.unicode) && m_input.length() < 11) {
				m_input += event.text.unicode;
			}
		}
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::BackSpace) {
				if (checkIfDirty(text_dirty, m_input)) {
					m_input.pop_back();
				}
			}
			if (event.key.code == sf::Keyboard::Enter && checkIfDirty(text_dirty, m_input)) {
				end = true;
			}
		}
	}
	m_window.clear();
	m_window.draw(m_board.getBoard());
	m_title.draw(m_window); 
	m_window.draw(m_textBox);

	checkIfDirty(text_dirty, m_input);

	if(text_dirty) {
		m_text.setString(m_input);
		m_window.draw(m_text);	
	}
	m_window.display();

	return end;
}

std::string const& InputScreen::getInput() const noexcept {
    return m_input;
}
} //arkanoid
