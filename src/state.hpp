#ifndef SFGE_STATE_H
#define SFGE_STATE_H

namespace sfge {
	class state {
		public:
			virtual void update() = 0;
			virtual void draw() = 0;
			virtual int end() = 0;
	};
}

#endif
