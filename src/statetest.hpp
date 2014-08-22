#ifndef SFGE_STATETEST_H
#define SFGE_STATETEST_H

#include <iostream>
#include <sstream>
#include <unistd.h>
#include <SFML/Graphics.hpp>
#include "state.hpp"

namespace sfge {
	class statetest : public virtual sfge::state {
		private:
			sf::RenderWindow * window;
			const sf::View * testview;
			sf::RectangleShape oneshape;
			sf::RectangleShape twoshape;
			sf::Clock clock;
			sf::Font font;
			sf::Text fpsText;
		public:
			statetest(sf::RenderWindow * window);
			~statetest();
			void update();
			void draw();
			int end();
	};
}

#endif
