#ifndef SFGE_GEARBOX_H
#define SFGE_GEARBOX_H

#include <vector>
#include "state.hpp"

namespace sfge {
	class state;
	class gearbox {
		private:
			int gear;
			std::vector<sfge::state*> states;
		public:
			gearbox();
			~gearbox();
			void add(sfge::state* state);
			bool change(int n);
			void update();
			void draw();
	};
}

#endif
