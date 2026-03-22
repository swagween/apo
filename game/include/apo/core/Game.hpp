
#pragma once

#include <SFML/Graphics.hpp>
#include <apo/core/AppData.hpp>
#include <apo/events/EventRegistry.hpp>
#include <apo/input/InputSystem.hpp>
#include <apo/state/StateManager.hpp>

namespace apo {

class Game {
  public:
	Game(ResourceManager& res, InputSystem& input, EventRegistry& events, AppData& data);

	void tick(EventRegistry& events);
	void draw(sf::RenderWindow& win);

  private:
	StateManager m_state_manager;
	sf::RectangleShape m_backdrop{};
	AppData* m_app_data;
	InputSystem* m_input;
	sf::Sprite m_cursor;
};

} // namespace apo
