
#pragma once

#include <SFML/Graphics.hpp>
#include <apo/core/Fwd.hpp>
#include <apo/utilities/Polymorphic.hpp>

namespace apo {

enum class GameStateType { menu, gameplay };

class IGameState : public UniquePolymorphic {
  public:
	IGameState(GameStateType type) : m_type{type} {}

	virtual void tick(InputSystem& input, EventRegistry& events) {};
	virtual void draw(sf::RenderWindow& win) {};

  private:
	GameStateType m_type;
};

} // namespace apo
