
#pragma once

#include <SFML/Graphics.hpp>
#include <apo/core/ResourceFinder.hpp>
#include <apo/core/TextureCatalog.hpp>

namespace apo {

struct Font {
	sf::Font title;
	sf::Font subtitle;
};

class ResourceManager {
  public:
	ResourceManager(ResourceFinder& finder);

  public:
	Font fonts;
	TextureCatalog textures;

  private:
};

} // namespace apo
