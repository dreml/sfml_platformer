#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

#include "components/Component.hpp"
#include "game/GameObject.hpp"

namespace sfmlp {

class AnimationComponent : public Component {
public:
  enum class Animation {
    Idle,
    Run
  };

public:
  AnimationComponent(GameObject& owner, std::string texturePath, sf::Vector2f spriteOrigin, sf::Vector2i spriteSize);

  virtual void update(float dt) override;
  virtual void draw(sf::RenderTarget& rt) const override;

  void playAnimation(Animation animation);

  sf::Vector2i getSpriteSize() const { return spriteSize; }

private:
  sf::Texture texture;
  sf::Sprite sprite;
  Animation currentAnimation;

  int framesSpeed = 10;
  int currentFrame = 0;
  sf::IntRect frameRec;
  float frameTimeCounter = 0.f;
  sf::Vector2i spriteSize;

  int columnsCount = 6;

  void updateAnimation(float dt);
};

} // namespace sfmlp
