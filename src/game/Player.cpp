#include "game/Player.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <stdexcept>

using namespace sfmlp;

Player::Player(sf::Vector2f p)
	: texture(),
		sprite(texture)
{
	setPosition(p);

	if (!texture.loadFromFile("assets/player.png")) {
		throw std::runtime_error("Failed to load player texture");
	}

	sprite.setOrigin({91.f, 91.f});
	sprite.setPosition(p);
	sprite.setTextureRect( sf::IntRect({0, 0}, {192, 192}));
};

void Player::update(float dt) {

}

void Player::draw(sf::RenderTarget &rt) const {
	rt.draw(sprite);
}
