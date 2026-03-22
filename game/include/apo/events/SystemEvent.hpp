
#pragma once

#include <apo/events/EventBase.hpp>
#include <string_view>

namespace apo {

struct LaunchFileEvent : Event<> {};
struct ExitGameEvent : Event<> {};
struct ReturnToTitleMenuEvent : Event<> {};

} // namespace apo
