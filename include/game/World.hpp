#pragma once

#include <SFML/System/Vector2.hpp>
#include <memory>
#include <vector>

#include "common/Types.hpp"
#include "game/Platform.hpp"
#include "game/Player.hpp"

namespace sfmlp {

class World {
public:
  World(sfmlp::ScreenDimensions sd, sf::Vector2f playerPosition);

  void update(float dt);
  void draw(sf::RenderTarget& rt) const;

  const std::vector<std::unique_ptr<Platform>>& getPlatforms() const { return platforms; };
  sfmlp::ScreenDimensions getWorldBoundaries() const { return worldBoundaries; };

protected:
  sfmlp::ScreenDimensions worldBoundaries;
  std::unique_ptr<Player> player;
  std::vector<std::unique_ptr<Platform>> platforms;

  void createPlatforms();
};

} // namespace sfmlp
