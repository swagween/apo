
#pragma once

#include <apo/utilities/ExecutablePath.hpp>
#include <filesystem>
#include <string>

namespace apo {

namespace fs = std::filesystem;

class ResourceFinder {
  public:
	explicit ResourceFinder();
	fs::path find_directory(fs::path const& target);

	[[nodiscard]] auto get_resource_path() const -> std::string { return paths.resources.string(); }

	struct {
		fs::path resources{};
	} paths{};
};

} // namespace apo
