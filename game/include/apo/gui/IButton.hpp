
#pragma once

#include <SFML/Graphics.hpp>
#include <apo/core/Fwd.hpp>
#include <apo/utilities/Polymorphic.hpp>

namespace apo {

enum class ButtonState { idle, hovered, pressed };

class IButton : public Polymorphic {
  public:
	virtual void handle_input(InputSystem& input);
	virtual void draw(sf::RenderWindow& win, sf::Vector2f position);

	[[nodiscard]] auto is_idle() const -> bool { return p_state == ButtonState::idle; }
	[[nodiscard]] auto is_hovered() const -> bool { return p_state == ButtonState::hovered; }
	[[nodiscard]] auto is_pressed() const -> bool { return p_state == ButtonState::pressed; }

  protected:
	ButtonState p_state;
};

} // namespace apo
