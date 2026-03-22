
#pragma once

#include <SFML/Graphics.hpp>

namespace apo {

struct AppData {
	sf::Vector2u window_dimensions{};
	[[nodiscard]] auto get_f_window_dimensions() const -> sf::Vector2f { return sf::Vector2f{window_dimensions}; }
};

} // namespace apo
