#pragma once

#include "GameObject.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

namespace sfmlp {

class Player : public GameObject {
public:
  Player(sf::Vector2f p);

  virtual void update(float dt) override;
  virtual void draw(sf::RenderTarget &rt) const override;

private:
  sf::Texture texture;
  sf::Sprite sprite;
};

} // namespace sfmlp
