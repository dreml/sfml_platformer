#include "components/PhysicsComponent.hpp"

#include <SFML/Window/Keyboard.hpp>

#include "game/GameObject.hpp"
#include "game/World.hpp"

using namespace sfmlp;

PhysicsComponent::PhysicsComponent(GameObject& owner, float gravity, float jumpForce)
  : Component(owner),
    gravity(gravity),
    jumpForce(jumpForce)
{}

void PhysicsComponent::update(float dt)
{
  applyGravity(dt);

  bIsOnGround = false;
  auto ownerAABB = owner.getAABB();

  for (const auto& platform : owner.getWorld()->getPlatforms()) {
    auto platformAABB = platform->getAABB();

    auto intersection = platform->getAABB().findIntersection(ownerAABB);
    if (!intersection) {
      continue;
    }

    float playerBottom = ownerAABB.position.y + ownerAABB.size.y;
    float platformTop = platformAABB.position.y;

    float overlapX = std::min(ownerAABB.position.x + ownerAABB.size.x, platformAABB.position.x + platformAABB.size.x) -
                     std::max(ownerAABB.position.x, platformAABB.position.x);

    if (playerBottom <= platformTop + 10.f && verticalVelocity >= 0.f && overlapX > 20.f) {
      owner.setPosition({ownerAABB.position.x, platformTop - ownerAABB.size.y});
      verticalVelocity = 0.f;
      bIsOnGround = true;
      break;
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
