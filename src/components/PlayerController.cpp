#include "components/PlayerController.hpp"

#include <SFML/Window/Keyboard.hpp>

#include "components/Component.hpp"
#include "game/GameObject.hpp"

using namespace sfmlp;

PlayerController::PlayerController(GameObject& owner, float speed)
  : Component(owner),
    speed(speed)
{}

void PlayerController::update(float dt)
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
    owner.move({-speed * dt, 0.f});
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
    owner.move({speed * dt, 0.f});
  }
}

void PlayerController::draw(sf::RenderTarget& rt) const {}
