#pragma once

#include "components/Component.hpp"

namespace sfmlp {

class PhysicsComponent : public Component {
public:
  PhysicsComponent(GameObject& owner, float gravity, float jumpForce);

  virtual void update(float dt) override;
  virtual void draw(sf::RenderTarget& rt) const override {};

  bool isOnGround() const { return bIsOnGround; };
  void jump();

protected:
  float gravity;
  bool bIsOnGround = false;
  float verticalVelocity;
  float jumpForce;

  void applyGravity(float dt);
};

} // namespace sfmlp
