
#pragma once

#include <apo/core/Fwd.hpp>
#include <apo/gui/TextButton.hpp>
#include <apo/state/gamestates/MenuState.hpp>

namespace apo {

class TitleMenu : public MenuState {
  public:
	TitleMenu(ResourceManager& res);

	void tick(InputSystem& input, EventRegistry& events) override;
	void draw(sf::RenderWindow& win) override;

  private:
	sf::Text m_title;
	TextButton m_play;
	TextButton m_exit;
};

} // namespace apo
