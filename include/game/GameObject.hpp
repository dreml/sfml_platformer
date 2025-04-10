#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>

namespace sfmlp {

class GameObject : public sf::Transformable {
public:
  virtual void update(float dt) = 0;
  virtual void draw(sf::RenderTarget& rt) const = 0;
};

} // namespace sfmlp
