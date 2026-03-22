
#include <apo/core/ResourceManager.hpp>
#include <apo/events/EventRegistry.hpp>
#include <apo/state/StateManager.hpp>

namespace apo {

StateManager::StateManager(ResourceManager& res, EventRegistry& events) {
	m_current_state = std::make_unique<TitleMenu>(res);

	// event subscriptions
	events.launch_file.attach_to(p_slot, [this, &res]() { m_current_state = std::make_unique<Shop>(res); });
}

void StateManager::tick(InputSystem& input, EventRegistry& events) { m_current_state->tick(input, events); }

} // namespace apo
