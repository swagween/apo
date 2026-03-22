
#include <apo/core/ResourceManager.hpp>

namespace apo {

ResourceManager::ResourceManager(ResourceFinder& finder)
	: textures{finder}, fonts{.title{finder.get_resource_path() + "/text/fonts/fantaisieartistique.medium.ttf"}, .subtitle{finder.get_resource_path() + "/text/fonts/pokoljaro.regular.otf"}} {}

} // namespace apo
