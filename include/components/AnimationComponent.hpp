#pragma once

#include "components/Component.hpp"
#include "game/GameObject.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

namespace sfmlp {

class AnimationComponent : public Component {
public:
  AnimationComponent(GameObject &owner, std::string texturePath,
                     sf::Vector2f spriteOrigin, sf::Vector2i spriteSize);

  virtual void update(float dt) override;
  virtual void draw(sf::RenderTarget &rt) const override;

private:
  sf::Texture texture;
  sf::Sprite sprite;
};

} // namespace sfmlp
