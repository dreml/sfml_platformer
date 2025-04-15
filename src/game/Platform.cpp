#include "game/Platform.hpp"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

#include "game/GameObject.hpp"
#include "game/World.hpp"

using namespace sfmlp;

Platform::Platform(World* world, sf::Vector2f size)
  : GameObject(world),
    size(size)
{}

void Platform::update(float dt)
{
}

void Platform::draw(sf::RenderTarget& rt) const
{
  auto r = sf::RectangleShape(size);
  r.setPosition(getPosition());
  r.setFillColor(sf::Color::Blue);

  rt.draw(r);
}

sf::FloatRect Platform::getAABB() const
{
  return sf::FloatRect(getPosition(), size);
}
