#include "components/AnimationComponent.hpp"

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <string>

#include "game/GameObject.hpp"

using namespace sfmlp;

AnimationComponent::AnimationComponent(GameObject& owner, std::string texturePath, sf::Vector2f spriteOrigin, sf::Vector2i spriteSize)
  : Component(owner),
    texture(),
    sprite(texture),
    spriteSize(spriteSize),
    frameRec(sf::IntRect({0, 0}, spriteSize))
{
  if (!texture.loadFromFile(texturePath)) {
    throw std::runtime_error("Failed to load player texture");
  }

  sprite.setOrigin(spriteOrigin);
  sprite.setPosition(owner.getPosition() + (sf::Vector2f)spriteSize / 2.f);
  sprite.setTextureRect(frameRec);
  currentAnimation = Animation::Idle;
}

void AnimationComponent::update(float dt)
{
  sprite.setPosition(owner.getPosition() + (sf::Vector2f)spriteSize / 2.f);
  sprite.setRotation(owner.getRotation());
  sprite.setScale(owner.getScale());

  updateAnimation(dt);
}

void AnimationComponent::draw(sf::RenderTarget& rt) const
{
  rt.draw(sprite);
}

void AnimationComponent::updateAnimation(float dt)
{
  frameTimeCounter += dt;
  if (frameTimeCounter >= 1.f / framesSpeed) {
    frameTimeCounter = 0;

    currentFrame++;
    if (currentFrame > (columnsCount - 1)) currentFrame = 0;

    auto frameRecX = currentFrame * spriteSize.x;
    frameRec = sf::IntRect({frameRecX, (int)currentAnimation * spriteSize.y}, spriteSize);

    sprite.setTextureRect(frameRec);
  }
}

void AnimationComponent::playAnimation(Animation animation)
{
  if (currentAnimation == animation) return;

  frameTimeCounter = 0;
  currentFrame = 0;
  currentAnimation = animation;
}
