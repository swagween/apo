
#pragma once

#include <apo/core/Fwd.hpp>
#include <apo/gui/TextButton.hpp>
#include <apo/state/gamestates/GameplayState.hpp>

namespace apo {

class Shop : public GameplayState {
  public:
	Shop(ResourceManager& res);

	void tick(InputSystem& input, EventRegistry& events) override;
	void draw(sf::RenderWindow& win) override;

  private:
};

} // namespace apo
