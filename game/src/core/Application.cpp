
#include <apo/core/Application.hpp>

namespace apo {

Application::Application() : m_game{m_resources, m_input_system, m_events, m_data} {

	// window stuff
	m_window = sf::RenderWindow{sf::VideoMode::getDesktopMode(), "Apothecary", sf::State::Fullscreen};
	m_data.window_dimensions = m_window.getSize();
	m_window.setMouseCursorVisible(false);

	// event subscriptions
	m_events.exit_game.attach_to(p_slot, &Application::shutdown, this);

	while (m_window.isOpen()) {
		m_input_system.update();
		while (std::optional const event = m_window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) { m_window.close(); }
			if (auto const* key_pressed = event->getIf<sf::Event::KeyPressed>()) {
				if (key_pressed->scancode == sf::Keyboard::Scancode::Escape) { shutdown(); }
			}

			// mouse buttons
			if (auto const* mouse_pressed = event->getIf<sf::Event::MouseButtonPressed>()) {
				if (mouse_pressed->button == sf::Mouse::Button::Left) { m_input_system.set_mouse_state(MouseButton::left, MouseButtonState::pressed); }
				if (mouse_pressed->button == sf::Mouse::Button::Right) { m_input_system.set_mouse_state(MouseButton::right, MouseButtonState::pressed); }
			}
			if (auto const* mouse_pressed = event->getIf<sf::Event::MouseButtonReleased>()) {
				if (mouse_pressed->button == sf::Mouse::Button::Left) { m_input_system.set_mouse_state(MouseButton::left, MouseButtonState::released); }
				if (mouse_pressed->button == sf::Mouse::Button::Right) { m_input_system.set_mouse_state(MouseButton::right, MouseButtonState::released); }
			}
		}

		// mouse cursor
		sf::Vector2i pixel = sf::Mouse::getPosition(m_window);
		sf::Vector2f world = m_window.mapPixelToCoords(pixel);
		m_input_system.set_cursor_position(world);

		// to be contained to a fixed timestep
		m_game.tick(m_events);

		m_window.clear();
		m_game.draw(m_window);
		m_window.display();
	}
}

void Application::shutdown() { m_window.close(); }

} // namespace apo
