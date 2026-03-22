
#include <apo/core/Game.hpp>
#include <apo/core/ResourceManager.hpp>
#include <apo/events/EventRegistry.hpp>
#include <apo/graphics/Colors.hpp>

namespace apo {

apo::Game::Game(ResourceManager& res, InputSystem& input, EventRegistry& events, AppData& data) : m_app_data{&data}, m_state_manager{res, events}, m_input{&input}, m_cursor{res.textures.get("cursor_arrow")} {
	m_backdrop.setFillColor(colors::black);
}

void Game::tick(EventRegistry& events) {
	m_state_manager.tick(*m_input, events);
	m_cursor.setPosition(m_input->get_cursor_position());
}

void Game::draw(sf::RenderWindow& win) {
	m_backdrop.setSize(m_app_data->get_f_window_dimensions());
	win.draw(m_backdrop);
	m_state_manager.draw(win);
	win.draw(m_cursor);
}

} // namespace apo
