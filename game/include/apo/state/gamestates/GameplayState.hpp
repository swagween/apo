
#pragma once

#include <apo/state/gamestates/IGameState.hpp>

namespace apo {

enum class GameplayStateType { shop };

class GameplayState : public IGameState {
  public:
	GameplayState(GameplayStateType type) : IGameState{GameStateType::gameplay}, m_type{type} {}
	virtual void tick(InputSystem& input, EventRegistry& events) {};
	virtual void draw(sf::RenderWindow& win) {};

  private:
	GameplayStateType m_type;
};

} // namespace apo
