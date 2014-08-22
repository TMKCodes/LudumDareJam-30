#ifndef SFGE_ENGINE_H
#define SFGE_ENGINE_H

#include <SFML/Graphics.hpp>

#include "gearbox.hpp"
#include "state.hpp"
#include "loaderstate.hpp"

namespace sfge {
	class engine {
		private:
			sf::RenderWindow * window;
			sfge::gearbox * gearbox;
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
