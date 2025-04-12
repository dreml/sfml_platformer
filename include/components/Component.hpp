#pragma once

#include "game/GameObject.hpp"

namespace sfmlp {

class GameObject;

class Component {
public:
  Component(GameObject& owner);

  virtual void update(float dt) = 0;
  virtual void draw(sf::RenderTarget& rt) const = 0;

protected:
  GameObject& owner;
};

} // namespace sfmlp
