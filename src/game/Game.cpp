#include "game/Game.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>

#include "common/Config.hpp"
#include "common/Types.hpp"

using namespace sfmlp;

Game::Game(ScreenDimensions sd)
  : screenDimensions(sd)
{
  sf::Vector2f playerPosition = {
    (float)(sd.width - sfmlp::Config::Player::SPRITE_SIZE.x) / 2,
    (float)(sd.height - sfmlp::Config::Player::SPRITE_SIZE.y) / 2
  };
  world = std::make_unique<World>(sd, playerPosition);
}

void Game::update(float dt)
{
  world->update(dt);
}

void Game::draw(sf::RenderTarget& rt) const
{
  world->draw(rt);
}
