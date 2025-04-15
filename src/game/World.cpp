#include "game/World.hpp"

#include <SFML/System/Vector2.hpp>
#include <memory>

#include "common/Config.hpp"
#include "common/Types.hpp"
#include "game/Platform.hpp"

using namespace sfmlp;

World::World(sfmlp::ScreenDimensions sd, sf::Vector2f playerPosition)
  : worldBoundaries(sd)
{
  player = std::make_unique<Player>(
    this,
    sf::Vector2f{playerPosition},
    sfmlp::Config::Player::TEXTURE_PATH,
    sfmlp::Config::Player::SPEED
  );

  createPlatforms();
}

void World::update(float dt)
{
  player->update(dt);

  for (auto& platform : platforms) {
    platform->update(dt);
  }
}

void World::draw(sf::RenderTarget& rt) const
{
  player->draw(rt);

  for (const auto& platform : platforms) {
    platform->draw(rt);
  }
}

void World::createPlatforms()
{
  // floor
  auto platform = std::make_unique<Platform>(this, sf::Vector2f{1920.f, 400.f});
  platform->setPosition({0.f, 800.f});
  platforms.push_back(std::move(platform));

  // platform 1
  platform = std::make_unique<Platform>(this, sf::Vector2f{400.f, 40.f});
  platform->setPosition({400.f, 650.f});
  platforms.push_back(std::move(platform));

  // platform 2
  platform = std::make_unique<Platform>(this, sf::Vector2f{400.f, 40.f});
  platform->setPosition({1200.f, 450.f});
  platforms.push_back(std::move(platform));

  // platform 3
  platform = std::make_unique<Platform>(this, sf::Vector2f{400.f, 40.f});
  platform->setPosition({500.f, 250.f});
  platforms.push_back(std::move(platform));
}
