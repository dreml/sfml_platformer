#include "game/Player.hpp"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

#include "components/AnimationComponent.hpp"
#include "components/PlayerController.hpp"

using namespace sfmlp;

Player::Player(sf::Vector2f p, std::string texturePath)
  : animComponent({*this, texturePath, {91.f, 91.f}, {192, 192}}),
    controller({*this, 500.f})
{
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
