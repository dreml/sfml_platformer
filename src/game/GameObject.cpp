#include "game/GameObject.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

#include "components/Component.hpp"
#include "game/World.hpp"

using namespace sfmlp;

GameObject::GameObject(World* world)
  : world(world)
{}

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
