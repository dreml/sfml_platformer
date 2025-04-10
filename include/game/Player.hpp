#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <string>

#include "GameObject.hpp"
#include "components/AnimationComponent.hpp"
#include "components/PlayerController.hpp"

namespace sfmlp {

class Player : public GameObject {
public:
  Player(sf::Vector2f p, std::string texturePath, float speed);

  virtual void update(float dt) override;
  virtual void draw(sf::RenderTarget& rt) const override;

private:
  std::unique_ptr<AnimationComponent> animComponent;
  std::unique_ptr<PlayerController> controller;
};

} // namespace sfmlp
