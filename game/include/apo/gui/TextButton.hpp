
#pragma once

#include <apo/core/Common.hpp>
#include <apo/core/Fwd.hpp>
#include <apo/gui/IButton.hpp>

namespace apo {

class TextButton : public IButton {
  public:
	TextButton(ResourceManager& res, std::string_view label, int size = default_button_text_size_v);

	void handle_input(InputSystem& input) override;
	void draw(sf::RenderWindow& win, sf::Vector2f position) override;

  private:
	sf::Text m_text;
};

} // namespace apo
