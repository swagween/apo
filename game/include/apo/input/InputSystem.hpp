
#pragma once

#include <SFML/Graphics.hpp>
#include <apo/utilities/BitFlags.hpp>

namespace apo {

enum class MouseButtonState { pressed, held, released };
enum class MouseButton { left, right };

struct MouseAction {
	MouseButton button;
	BitFlags<MouseButtonState> state;
};

class InputSystem {
  public:
	void update() {
		m_left_mouse_button.state.reset(MouseButtonState::pressed);
		m_left_mouse_button.state.reset(MouseButtonState::released);
		m_right_mouse_button.state.reset(MouseButtonState::pressed);
		m_right_mouse_button.state.reset(MouseButtonState::released);
	}

	void set_mouse_state(MouseButton which, MouseButtonState state) {
		auto& button = which == MouseButton::left ? m_left_mouse_button : m_right_mouse_button;
		switch (state) {
		case MouseButtonState::pressed:
			button.state.set(MouseButtonState::pressed);
			button.state.set(MouseButtonState::held);
			break;
		case MouseButtonState::released:
			button.state.set(MouseButtonState::released);
			button.state.reset(MouseButtonState::held);
			break;
		default: break;
		}
	}

	void set_cursor_position(sf::Vector2f to) { m_cursor_position = to; }

	[[nodiscard]] auto get_cursor_position() const -> sf::Vector2f { return m_cursor_position; }
	[[modiscard]] auto mouse_button_pressed(MouseButton which) const -> bool {
		auto& button = which == MouseButton::left ? m_left_mouse_button : m_right_mouse_button;
		return button.state.test(MouseButtonState::pressed);
	}

  private:
	sf::Vector2f m_cursor_position{};
	MouseAction m_left_mouse_button{};
	MouseAction m_right_mouse_button{};
};

} // namespace apo
