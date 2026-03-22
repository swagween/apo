
#pragma once

#include <SFML/Graphics.hpp>
#include <apo/core/Fwd.hpp>

namespace apo {

class TextureCatalog {
  public:
	TextureCatalog(ResourceFinder& finder);
	sf::Texture const& get(std::string_view key) { return m_textures.contains(key.data()) ? m_textures.at(key.data()) : m_null_texture; }

  private:
	std::unordered_map<std::string, sf::Texture> m_textures{};
	sf::Texture m_null_texture{};
};

} // namespace apo
