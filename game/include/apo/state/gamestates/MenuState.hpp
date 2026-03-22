
#pragma once

#include <apo/state/gamestates/IGameState.hpp>

namespace apo {

enum class MenuStateType { title };

class MenuState : public IGameState {
  public:
	MenuState(MenuStateType type) : IGameState{GameStateType::menu}, m_type{type} {}
	virtual void tick(InputSystem& input, EventRegistry& events) {};
	virtual void draw(sf::RenderWindow& win) {};

  private:
	MenuStateType m_type;
};

} // namespace apo
