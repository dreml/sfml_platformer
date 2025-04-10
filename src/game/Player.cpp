#include "game/Player.hpp"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

#include "common/Config.hpp"
#include "components/AnimationComponent.hpp"
#include "components/PlayerController.hpp"

using namespace sfmlp;

Player::Player(sf::Vector2f p, std::string texturePath, float speed)
  : animComponent(
      {*this,
       texturePath,
       {(float)sfmlp::Config::Player::SPRITE_SIZE.x / 2, (float)sfmlp::Config::Player::SPRITE_SIZE.y / 2},
       {sfmlp::Config::Player::SPRITE_SIZE.x, sfmlp::Config::Player::SPRITE_SIZE.y}}
    ),
    controller({*this, speed})
{
  setOrigin({(float)sfmlp::Config::Player::SPRITE_SIZE.x / 2, (float)sfmlp::Config::Player::SPRITE_SIZE.y / 2});
  setPosition(p);
};

void Player::update(float dt)
{
  animComponent.update(dt);
  controller.update(dt);
}

void Player::draw(sf::RenderTarget& rt) const
{
  animComponent.draw(rt);
}
