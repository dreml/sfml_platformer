#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

#include "GameObject.hpp"
#include "components/AnimationComponent.hpp"
#include "components/PlayerController.hpp"

namespace sfmlp {

class Player : public GameObject {
public:
  Player(sf::Vector2f p, std::string texturePath);

  virtual void update(float dt) override;
  virtual void draw(sf::RenderTarget& rt) const override;

private:
  AnimationComponent animComponent;
  PlayerController controller;
};

} // namespace sfmlp
