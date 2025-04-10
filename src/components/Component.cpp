#include "components/Component.hpp"

#include "game/GameObject.hpp"

using namespace sfmlp;

Component::Component(GameObject& owner) : owner(owner) {};
