#include "components/PlayerController.hpp"

#include <SFML/Window/Keyboard.hpp>
#include <cstdlib>

#include "components/Component.hpp"
#include "components/PhysicsComponent.hpp"
#include "game/GameObject.hpp"

using namespace sfmlp;

PlayerController::PlayerController(GameObject& owner, float speed)
  : Component(owner),
    speed(speed)
{}

void PlayerController::update(float dt)
{
  auto scale = owner.getScale();
  int direction = 0;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
    direction = -1;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
    direction = 1;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
    if (auto physicsComponent = owner.getComponent<PhysicsComponent>()) {
      physicsComponent->jump();
    }
  }

  bIsMoving = direction != 0;
  if (bIsMoving) {
    owner.move({direction * speed * dt, 0.f});
    owner.setScale({direction * std::abs(scale.x), scale.y});
  }
}

void PlayerController::draw(sf::RenderTarget& rt) const {}
