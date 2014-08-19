#include "engine.hpp"

sfge::engine::engine() {
	this->status = true;
	this->window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Simple Fast Game Engine");
	this->window->setVerticalSyncEnabled(true);
	this->window->setFramerateLimit(60);
}

sfge::engine::~engine() {
	delete this->window;
}

bool sfge::engine::running() {
	return this->status;
}

void sfge::engine::update() {
	if(this->window->isOpen()) {
		sf::Event event;
		while(this->window->pollEvent(event)) {
			if(event.type == sf::Event::Closed) {
				this->window->close();
				this->status = false;
			}
		}
	}
}

void sfge::engine::draw() {
	if(this->window->isOpen()) {
		this->window->clear(sf::Color::Black);

		this->window->display();
	}
}
