#pragma once

#include <SFML/System/Vector2.hpp>
#include <string>

namespace sfmlp {
namespace Config {

  inline constexpr int WINDOW_WIDTH = 1920;
  inline constexpr int WINDOW_HEIGHT = 1080;

  inline const std::string BACKGROUND_MUSIC_PATH = "";

  namespace Player {

    inline constexpr float SPEED = 500.f;
    inline const std::string TEXTURE_PATH = "assets/player.png";
    inline const sf::Vector2i SPRITE_SIZE = {192, 192};

  } // namespace Player

} // namespace Config
} // namespace sfmlp
