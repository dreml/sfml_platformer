#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>

namespace sfmlp {

class World;
class Component;

class GameObject : public sf::Transformable {
public:
  GameObject(World* world);

  virtual void update(float dt);
  virtual void draw(sf::RenderTarget& rt) const;

  virtual sf::FloatRect getAABB() const = 0;

  World* getWorld() const { return world; };

  template <typename T>
  T* getComponent()
  {
    for (auto component : components) {
      if (auto casted = dynamic_cast<T*>(component)) {
        return casted;
      }
    }

    return nullptr;
  }

protected:
  World* world;
  std::vector<Component*> components;

  void addComponent(Component* component)
  {
    components.push_back(component);
  }
};

} // namespace sfmlp
