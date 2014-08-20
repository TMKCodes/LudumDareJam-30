#ifndef SFGE_STATETEST_H
#define SFGE_STATETEST_H

#include "state.hpp"

namespace sfge {
	class statetest : public virtual sfge::state {
		public:
			void update();
			void draw();
			int end();
	};
}

#endif
