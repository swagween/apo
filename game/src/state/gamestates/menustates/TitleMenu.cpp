
#include <apo/core/ResourceManager.hpp>
#include <apo/events/EventRegistry.hpp>
#include <apo/graphics/Colors.hpp>
#include <apo/input/InputSystem.hpp>
#include <apo/state/gamestates/menustates/TitleMenu.hpp>

namespace apo {

TitleMenu::TitleMenu(ResourceManager& res) : MenuState{MenuStateType::title}, m_title{res.fonts.title}, m_play{res, "play"}, m_exit{res, "exit"} {
	m_title.setString("Apothecary");
	m_title.setCharacterSize(360);
	m_title.setOrigin(m_title.getLocalBounds().getCenter());
	m_title.setFillColor(colors::white);
}

void TitleMenu::tick(InputSystem& input, EventRegistry& events) {
	m_play.handle_input(input);
	m_exit.handle_input(input);
	if (m_play.is_pressed()) { events.launch_file.dispatch(); }
	if (m_exit.is_pressed()) { events.exit_game.dispatch(); }
}

void TitleMenu::draw(sf::RenderWindow& win) {
	m_title.setPosition(win.getDefaultView().getCenter() - sf::Vector2f{0.f, 360.f});
	win.draw(m_title);

	m_play.draw(win, win.getDefaultView().getCenter() + sf::Vector2f{0.f, 40.f});
	m_exit.draw(win, win.getDefaultView().getCenter() + sf::Vector2f{0.f, 160.f});
}

} // namespace apo
