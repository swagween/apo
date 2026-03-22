
#include <apo/core/ResourceFinder.hpp>

namespace apo {

ResourceFinder::ResourceFinder() { paths.resources = find_directory(fs::path{"resources"}); }

fs::path ResourceFinder::find_directory(fs::path const& target) {
	auto execpy = fs::path{executable_path()};
	auto check = [target](fs::path const& prefix) {
		auto path = prefix / target;
		if (fs::is_directory(path)) { return path; }
		return fs::path{};
	};
	while (!execpy.empty()) {
		if (auto ret = check(execpy); !ret.empty()) { return ret; }
		auto parent = execpy.parent_path();
		if (execpy == parent) { break; }
		execpy = std::move(parent);
	}
	return {};
}

} // namespace apo
