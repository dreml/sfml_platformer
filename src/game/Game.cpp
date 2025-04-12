#include "game/Game.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>

#include "common/Config.hpp"
#include "common/Types.hpp"
#include "game/Player.hpp"

using namespace sfmlp;

Game::Game(ScreenDimensions sd)
  : screenDimensions(sd)
{
  sf::Vector2f playerPosition = {
    (float)(sd.width - sfmlp::Config::Player::SPRITE_SIZE.x) / 2,
    (float)(sd.height - sfmlp::Config::Player::SPRITE_SIZE.y) / 2
  };
  player = std::make_unique<Player>(
    sf::Vector2f{playerPosition},
    sfmlp::Config::Player::TEXTURE_PATH,
    sfmlp::Config::Player::SPEED
  );
}

void Game::update(float dt)
{
  player->update(dt);
}

void Game::draw(sf::RenderTarget& rt) const
{
  player->draw(rt);
}
