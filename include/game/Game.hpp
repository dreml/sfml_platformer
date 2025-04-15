#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <memory>

#include "common/Types.hpp"
#include "game/World.hpp"

namespace sfmlp {

class Game {
public:
  Game() = delete;
  Game(ScreenDimensions sd);

  void update(float dt);
  void draw(sf::RenderTarget& rt) const;

private:
  ScreenDimensions screenDimensions;
  std::unique_ptr<World> world;
};

} // namespace sfmlp
