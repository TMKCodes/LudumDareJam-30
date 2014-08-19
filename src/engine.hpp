#ifndef SFGE_ENGINE_H
#define SFGE_ENGINE_H

#include <SFML/Graphics.hpp>

namespace sfge {
	class engine {
		private:
			sf::RenderWindow * window;
			bool status;
		public:	
			engine();
			~engine();
			bool running();
			void update();
			void draw();
	};
}

#endif
