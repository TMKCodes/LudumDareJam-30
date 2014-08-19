#include <iostream>
#include "engine.hpp"

int main() {
	std::cout << "Main function launched." << std::endl;
	sfge::engine * engine = new sfge::engine();
	while(engine->running()) {
		engine->update();
		engine->draw();
	}
	delete engine;
	return 0;
}

