#include "game/GameObject.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

using namespace sfmlp;

void GameObject::update(float dt)
{
  for (auto component : components) {
    component->update(dt);
  }
}

void GameObject::draw(sf::RenderTarget& rt) const
{
  for (auto component : components) {
    component->draw(rt);
  }
}
