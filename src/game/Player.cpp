#include "game/Player.hpp"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <string>

#include "common/Config.hpp"
#include "components/AnimationComponent.hpp"
#include "components/PhysicsComponent.hpp"
#include "components/PlayerController.hpp"
#include "game/GameObject.hpp"
#include "game/World.hpp"

using namespace sfmlp;

Player::Player(World* world, sf::Vector2f p, std::string texturePath, float speed)
  : GameObject(world)
{
  setOrigin({(float)sfmlp::Config::Player::SPRITE_SIZE.x / 2, (float)sfmlp::Config::Player::SPRITE_SIZE.y / 2});
  setPosition(p);

  animComponent = std::make_unique<AnimationComponent>(
    *this,
    texturePath,
    sf::Vector2f{
      (float)sfmlp::Config::Player::SPRITE_SIZE.x / 2,
      (float)sfmlp::Config::Player::SPRITE_SIZE.y / 2
    },
    sf::Vector2i{
      sfmlp::Config::Player::SPRITE_SIZE.x,
      sfmlp::Config::Player::SPRITE_SIZE.y
    }
  );
  controller = std::make_unique<PlayerController>(*this, speed);
  physicsComponent = std::make_unique<PhysicsComponent>(*this, sfmlp::Config::GRAVITY, sfmlp::Config::Player::JUMP_FORCE);

  addComponent(animComponent.get());
  addComponent(controller.get());
  addComponent(physicsComponent.get());
};

void Player::update(float dt)
{
  GameObject::update(dt);

  if (controller->isMoving()) {
    animComponent->playAnimation(AnimationComponent::Animation::Run);
  } else {
    animComponent->playAnimation(AnimationComponent::Animation::Idle);
  }
}

void Player::draw(sf::RenderTarget& rt) const
{
  GameObject::draw(rt);

  auto r = sf::RectangleShape((sf::Vector2f)animComponent->getSpriteSize());
  r.setPosition(getPosition());
  r.setFillColor(sf::Color{255, 0, 0, 120});
  rt.draw(r);
}

sf::FloatRect Player::getAABB() const
{
  return {getPosition(), (sf::Vector2f)animComponent->getSpriteSize()};
}
