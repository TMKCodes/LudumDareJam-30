#include "engine.hpp"

sfge::engine::engine() {
	this->status = true;
	this->window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Simple Fast Game Engine");
	//this->window->setVerticalSyncEnabled(true);
	//this->window->setFramerateLimit(60);

	this->gearbox = new sfge::gearbox();

	sfge::state * loaderstate = new sfge::loaderstate(window);
	this->gearbox->add(loaderstate);
}

sfge::engine::~engine() {
	delete this->gearbox;
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
		this->gearbox->update();
	}
}

void sfge::engine::draw() {
	if(this->window->isOpen()) {
		this->window->clear(sf::Color::Black);
		this->gearbox->draw();
		this->window->display();
	}
}
