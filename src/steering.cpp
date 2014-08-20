#include "steering.hpp"

void sfge::steering::assing(sf::Keyboard::Key key, std::string name) {
	this->keys.insert(std::pair<std::string, sf::Keyboard::Key>(name, key));
}

bool sfge::steering::isPressed(std::string name) {
	return sf::Keyboard::isKeyPressed(this->keys[name]);
}
