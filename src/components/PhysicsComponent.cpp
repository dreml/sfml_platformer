#include "components/PhysicsComponent.hpp"

#include <SFML/Window/Keyboard.hpp>

#include "game/GameObject.hpp"

using namespace sfmlp;

PhysicsComponent::PhysicsComponent(GameObject& owner, float gravity, float jumpForce)
  : Component(owner),
    gravity(gravity),
    jumpForce(jumpForce)
{}

void PhysicsComponent::update(float dt)
{
  applyGravity(dt);

  if (owner.getPosition().y + owner.getAABB().size.y >= 800.f) {
    bIsOnGround = true;
    if (verticalVelocity >= 0.f) {
      verticalVelocity = 0.f;
    }
  }

  owner.move({0.f, verticalVelocity * dt});
}

void PhysicsComponent::applyGravity(float dt)
{
  if (!isOnGround()) {
    verticalVelocity += gravity * dt;
  }
}

void PhysicsComponent::jump()
{
  if (!isOnGround()) return;

  verticalVelocity = -jumpForce;
  bIsOnGround = false;
}
