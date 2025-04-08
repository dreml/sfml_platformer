#pragma once

#include "common/Types.hpp"
#include "game/Player.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <memory>

namespace sfmlp {

class Game {

public:
  Game() = delete;
  Game(ScreenDimensions sd);

  void update(float dt);
  void draw(sf::RenderTarget &rt) const;

private:
  ScreenDimensions screenDimensions;
  std::unique_ptr<Player> player;
};

} // namespace sfmlp
