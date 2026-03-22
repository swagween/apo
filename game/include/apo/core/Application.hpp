
#pragma once

#include <SFML/Graphics.hpp>
#include <apo/core/AppData.hpp>
#include <apo/core/Game.hpp>
#include <apo/core/ResourceFinder.hpp>
#include <apo/core/ResourceManager.hpp>
#include <apo/events/EventRegistry.hpp>
#include <apo/events/Subscription.hpp>
#include <apo/input/InputSystem.hpp>
#include <memory>

namespace apo {

class Application {
  public:
	Application();
	void shutdown();

  private:
	AppData m_data{};
	sf::RenderWindow m_window;
	EventRegistry m_events;
	ResourceFinder m_finder{};
	ResourceManager m_resources{m_finder};
	InputSystem m_input_system{};
	Game m_game;

	std::shared_ptr<Slot const> p_slot{std::make_shared<Slot const>()};
};

} // namespace apo
