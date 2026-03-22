
#include <apo/core/ResourceManager.hpp>
#include <apo/events/EventRegistry.hpp>
#include <apo/graphics/Colors.hpp>
#include <apo/input/InputSystem.hpp>
#include <apo/state/gamestates/gameplaystates/Shop.hpp>

namespace apo {

Shop::Shop(ResourceManager& res) : GameplayState{GameplayStateType::shop} {}

void Shop::tick(InputSystem& input, EventRegistry& events) {}

void Shop::draw(sf::RenderWindow& win) {}

} // namespace apo
