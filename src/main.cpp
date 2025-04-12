#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>

#include "common/Config.hpp"
#include "common/Types.hpp"
#include "game/Game.hpp"

int main()
{
  auto screenDimensions = sfmlp::ScreenDimensions{
    sfmlp::Config::WINDOW_WIDTH,
    sfmlp::Config::WINDOW_HEIGHT
  };

  auto window = sf::RenderWindow(
    sf::VideoMode({sfmlp::Config::WINDOW_WIDTH, sfmlp::Config::WINDOW_HEIGHT}),
    "SFML Test"
  );
  window.setFramerateLimit(144);

  sf::Clock frameClock;
  sfmlp::Game game(screenDimensions);

  // ground
  auto r = sf::RectangleShape({1920, 1080});
  r.setPosition({0.f, 834.f});
  r.setFillColor(sf::Color::Green);

  while (window.isOpen()) {
    while (auto event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      } else if (const auto keyPressed = event->getIf<sf::Event::KeyPressed>()) {
        if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
          window.close();
        }
      }
    }

    auto dt = frameClock.restart();
    game.update(dt.asSeconds());

    window.clear(sf::Color::White);
    window.draw(r);
    game.draw(window);
    window.display();
  }

  return 0;
}
