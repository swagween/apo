
#pragma once

#include <SFML/Graphics.hpp>
#include <apo/core/Fwd.hpp>
#include <apo/events/Subscription.hpp>
#include <apo/state/gamestates/IGameState.hpp>
#include <apo/state/gamestates/gameplaystates/Shop.hpp>
#include <apo/state/gamestates/menustates/TitleMenu.hpp>
#include <memory>

namespace apo {

class StateManager {
  public:
	StateManager(ResourceManager& res, EventRegistry& events);

	void tick(InputSystem& input, EventRegistry& events);
	void draw(sf::RenderWindow& win) { m_current_state->draw(win); }

  private:
	std::unique_ptr<IGameState> m_current_state;

	std::shared_ptr<Slot const> p_slot{std::make_shared<Slot const>()};
};

} // namespace apo
