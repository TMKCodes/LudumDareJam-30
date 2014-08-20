#include "gearbox.hpp"

sfge::gearbox::gearbox() {

}

sfge::gearbox::~gearbox() {
	for(int i = this->states.size()-1; i >= 0; i--) {
		this->states.pop_back();
	}
}

void sfge::gearbox::add(sfge::state* state) {
	this->states.push_back(state);
}

bool sfge::gearbox::change(int n) {
	if((unsigned int)n < this->states.size()) {
		this->gear = n;	
		return true;
	} else {
		return false;
	}
}

void sfge::gearbox::update() {
	sfge::state* state = this->states.at(this->gear);
	state->update();
}

void sfge::gearbox::draw() {
	sfge::state* state = this->states.at(this->gear);
	state->draw();
	int end = state->end();
	if(end != 0) {
		this->change(end);
	}
}
