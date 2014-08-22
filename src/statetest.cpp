#include "statetest.hpp"

sfge::statetest::statetest(sf::RenderWindow * window) {
	this->window = window;
	this->testview = &window->getView();
	sf::Vector2f wsize = (sf::Vector2f)this->testview->getSize();
	this->oneshape = sf::RectangleShape(sf::Vector2f(50, 50));
	this->oneshape.setPosition(sf::Vector2f(wsize.x/2, wsize.y/4));
	this->twoshape = sf::RectangleShape(sf::Vector2f(50, 50));
	this->twoshape.setPosition(sf::Vector2f(wsize.x/2, wsize.y-wsize.y/4));
	this->clock = sf::Clock();
	this->font = sf::Font();
	if(!font.loadFromFile("/usr/share/LD30/assets/fonts/arial.ttf")) {
		std::cout << "Failed to load assets/fonts/arial.ttf font" << std::endl;
	} else {
		this->fpsText = sf::Text();
		this->fpsText.setFont(font);
		this->fpsText.setCharacterSize(24);
	}
}

sfge::statetest::~statetest() {
	delete testview;
}

void sfge::statetest::update() {
	float oneshapex = 0;
	float oneshapey = 0;
	float twoshapex = 0;
	float twoshapey = 0;
	float speed = 0.5;
	sf::Vector2f oneshapexy = this->oneshape.getPosition();
	sf::Vector2f twoshapexy = this->twoshape.getPosition();
	sf::Vector2f wsize = (sf::Vector2f)this->testview->getSize();
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if(oneshapexy.y > 0)
			oneshapey -= speed;	
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if(oneshapexy.y < wsize.y-50)
			oneshapey += speed; 
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if(oneshapexy.x > 0)
			oneshapex -= speed;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if(oneshapexy.x < wsize.x-50)
			oneshapex += speed;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if(twoshapexy.y > 0)
			twoshapey -= speed;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if(twoshapexy.y < wsize.y-50)
			twoshapey += speed;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if(twoshapexy.x > 0)
			twoshapex -= speed;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if(twoshapexy.x < wsize.x-50)
			twoshapex += speed;
	}
	this->oneshape.move(sf::Vector2f(oneshapex, oneshapey));
	this->twoshape.move(sf::Vector2f(twoshapex, twoshapey));
	if(this->oneshape.getGlobalBounds().intersects(this->twoshape.getGlobalBounds())) {
		this->twoshape.move(sf::Vector2f(oneshapex/2, oneshapey/2));
	}
	if(this->twoshape.getGlobalBounds().intersects(this->oneshape.getGlobalBounds())) {
		this->oneshape.move(sf::Vector2f(-oneshapex, -oneshapey));
		this->twoshape.move(sf::Vector2f(-twoshapex, -twoshapey));
	}
	float currentTime = this->clock.restart().asSeconds();
	float fps = 1.f / currentTime;
	std::ostringstream ss;
	ss << "FPS: " << fps;
	this->fpsText.setString(ss.str());
	usleep(1000);
}

void sfge::statetest::draw() {
	this->window->setView(*this->testview);
	this->window->draw(this->oneshape);
	this->window->draw(this->twoshape);
	this->window->draw(this->fpsText);
}

int sfge::statetest::end() {
	return 0;
}
