
#pragma once

#include <ksignal/ksignal.hpp>

namespace apo {

template <typename... Args>
using Event = ksignal::Signal<Args...>;

} // namespace apo
