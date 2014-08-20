#ifndef SFGE_STATETEST_H
#define SFGE_STATETEST_H

#include <iostream>
#include <sstream>
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
			float lastTime;
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
