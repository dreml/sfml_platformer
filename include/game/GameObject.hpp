#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <vector>

namespace sfmlp {

class Component;

class GameObject : public sf::Transformable {
public:
  virtual void update(float dt);
  virtual void draw(sf::RenderTarget& rt) const;

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
  std::vector<Component*> components;

  void addComponent(Component* component)
  {
    components.push_back(component);
  }
};

} // namespace sfmlp
