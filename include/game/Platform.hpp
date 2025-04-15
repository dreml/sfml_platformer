#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>

#include "game/GameObject.hpp"

namespace sfmlp {

class World;

class Platform : public GameObject {
public:
  Platform(World* world, sf::Vector2f size);

  void update(float dt) override;
  void draw(sf::RenderTarget& rt) const override;

  sf::FloatRect getAABB() const override;

protected:
  sf::Vector2f size;
};

} // namespace sfmlp
