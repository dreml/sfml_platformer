#include "game/Game.hpp"
#include "common/Types.hpp"
#include "game/Player.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>

using namespace sfmlp;

Game::Game(ScreenDimensions sd)
	: screenDimensions(sd)
{
	player = std::make_unique<Player>(sf::Vector2f{(float)sd.width/2, (float)sd.height/2});
}

void Game::update(float dt) {

}

void Game::draw(sf::RenderTarget &rt) const {
	player->draw(rt);
}
