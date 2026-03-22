
#include <apo/core/ResourceFinder.hpp>
#include <apo/core/TextureCatalog.hpp>

namespace apo {

TextureCatalog::TextureCatalog(ResourceFinder& finder) {
	namespace fs = std::filesystem;
	auto p_folder{fs::path{"image"}};
	auto p_app{p_folder / fs::path{"app"}};
	auto image_dir = fs::path{finder.get_resource_path()} / "image";

	// null texture for lookup failures
	if (!m_null_texture.loadFromFile(finder.get_resource_path() / p_app / fs::path{"null.png"})) {};

	// recursively load textures
	for (auto const& image_genre : fs::recursive_directory_iterator(image_dir)) {
		if (!image_genre.is_directory()) { continue; }
		for (auto const& image : fs::recursive_directory_iterator(image_genre)) {
			if (image.path().extension() != ".png") { continue; }
			auto image_str = image.path().filename().string();
			m_textures.insert({image_str.substr(0, image_str.find('.')), sf::Texture{image.path()}});
		}
	}
}

} // namespace apo
