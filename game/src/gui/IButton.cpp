
#include <apo/gui/IButton.hpp>
#include <apo/input/InputSystem.hpp>

namespace apo {

void IButton::handle_input(InputSystem& input) {
	if (is_hovered() && input.mouse_button_pressed(MouseButton::left)) { p_state = ButtonState::pressed; }
}

void IButton::draw(sf::RenderWindow& win, sf::Vector2f position) {}

} // namespace apo
