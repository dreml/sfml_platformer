#pragma once

#include "components/Component.hpp"

namespace sfmlp {

class PlayerController : public Component {
public:
  PlayerController(GameObject& owner, float speed);

  virtual void update(float dt) override;
  virtual void draw(sf::RenderTarget& rt) const override;

private:
  float speed;
};

} // namespace sfmlp
