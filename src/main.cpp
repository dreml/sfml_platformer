#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include "common/Constants.hpp"
#include "common/Types.hpp"
#include "game/Game.hpp"

int main () {
	auto screenDimensions = sfmlp::ScreenDimensions{sfmlp::Constants::WINDOW_WIDTH, sfmlp::Constants::WINDOW_HEIGHT};

	auto window = sf::RenderWindow(sf::VideoMode({sfmlp::Constants::WINDOW_WIDTH, sfmlp::Constants::WINDOW_HEIGHT}), "SFML Test");
	window.setFramerateLimit(144);

	sfmlp::Game game(screenDimensions);

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

		window.clear(sf::Color::White);
		game.draw(window);
		window.display();
	}

	return 0;
}
