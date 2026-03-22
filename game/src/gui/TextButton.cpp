
#include <apo/core/ResourceManager.hpp>
#include <apo/graphics/Colors.hpp>
#include <apo/gui/TextButton.hpp>
#include <apo/input/InputSystem.hpp>

namespace apo {

TextButton::TextButton(ResourceManager& res, std::string_view label, int size) : m_text{res.fonts.subtitle} {
	m_text.setString(label.data());
	m_text.setCharacterSize(size);
	m_text.setOrigin(m_text.getLocalBounds().getCenter());
}

void TextButton::handle_input(InputSystem& input) {
	p_state = m_text.getGlobalBounds().contains(input.get_cursor_position()) ? ButtonState::hovered : ButtonState::idle;
	IButton::handle_input(input);
	switch (p_state) {
	case ButtonState::idle: m_text.setFillColor(colors::brown); break;
	case ButtonState::hovered: m_text.setFillColor(colors::white); break;
	case ButtonState::pressed: break;
	}
}

void TextButton::draw(sf::RenderWindow& win, sf::Vector2f position) {
	m_text.setPosition(position);
	win.draw(m_text);
}

} // namespace apo
