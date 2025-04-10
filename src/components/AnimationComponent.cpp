#include "components/AnimationComponent.hpp"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

#include "game/GameObject.hpp"

using namespace sfmlp;

AnimationComponent::AnimationComponent(GameObject& owner, std::string texturePath, sf::Vector2f spriteOrigin, sf::Vector2i spriteSize)
  : Component(owner),
    texture(),
    sprite(texture)
{
  if (!texture.loadFromFile(texturePath)) {
    throw std::runtime_error("Failed to load player texture");
  }

  sprite.setOrigin(spriteOrigin);
  sprite.setPosition(owner.getPosition());
  sprite.setTextureRect(sf::IntRect({0, 0}, spriteSize));
}

void AnimationComponent::update(float dt)
{
  sprite.setPosition(owner.getPosition());
  sprite.setRotation(owner.getRotation());
  sprite.setScale(owner.getScale());
}

void AnimationComponent::draw(sf::RenderTarget& rt) const
{
  rt.draw(sprite);
}
