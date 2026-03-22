
#pragma once

#include <apo/core/Application.hpp>
#include <optional>

namespace apo {

class Launcher {
  public:
	Launcher() {}
	void run();

  private:
	std::optional<apo::Application> m_app{};
};

} // namespace apo
