#ifndef SFGE_STEERING_H
#define SFGE_STEERING_H

#include <map>
#include <string>
#include <SFML/Window.hpp>

namespace sfge {
	class steering {
		private:
			std::map<std::string, sf::Keyboard::Key> keys;
		public: 
			void assing(sf::Keyboard::Key key, std::string name);
			bool isPressed(std::string name); 
	};
}

#endif
