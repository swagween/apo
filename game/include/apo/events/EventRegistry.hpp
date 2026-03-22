
#pragma once

#include <apo/events/SystemEvent.hpp>

namespace apo {

struct EventRegistry {
	LaunchFileEvent launch_file{};
	ExitGameEvent exit_game{};
	ReturnToTitleMenuEvent return_to_title_menu{};
};

} // namespace apo
