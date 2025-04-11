#include "game/Player.hpp"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <string>

#include "common/Config.hpp"
#include "components/AnimationComponent.hpp"
#include "components/PlayerController.hpp"

using namespace sfmlp;

Player::Player(sf::Vector2f p, std::string texturePath, float speed)
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
};

void Player::update(float dt)
{
  animComponent->update(dt);
  controller->update(dt);

  if (controller->isMoving()) {
    animComponent->playAnimation(AnimationComponent::Animation::Run);
  } else {
    animComponent->playAnimation(AnimationComponent::Animation::Idle);
  }
}

void Player::draw(sf::RenderTarget& rt) const
{
  animComponent->draw(rt);
}
