#include "Game.h"

m_keyboard Game::keyboard;
m_mouse Game::mouse;


void Game::init() {
	window.create(sf::VideoMode(width, height), title);
	window.setFramerateLimit(70);
	if (limit_frame != 0) window.setFramerateLimit(limit_frame);
}

Game::Game(std::string title, unsigned int width, unsigned int height, unsigned int limit_frame) {
	this->title = title;
	this->width = width;
	this->height = height;
	this->limit_frame = limit_frame;
	this->init();
}



void Game::handleKeyboard(const msf::Keyboard key, bool state) {
	switch (key) {
		case msf::Keyboard::W:
		case msf::Keyboard::A:
		case msf::Keyboard::D:
		case msf::Keyboard::S:
		case msf::Keyboard::LControl:
		case msf::Keyboard::RControl:
		case msf::Keyboard::LShift:
		case msf::Keyboard::RShift:
			keyboard.setKey(key, state);
		default:
			break;
	}
}

void Game::handleMouse(const msf::Button btn, bool state) {
	switch (btn) {
		case msf::Button::Left:
		case msf::Button::Right:
		case msf::Button::Middle:
			mouse.setButton(btn, state);
		default:
			break;
	}
}

void Game::handleInput(sf::Event* event) {

	switch (event->type) {
		case sf::Event::EventType::Closed:
			window.close();
			break;
		case sf::Event::EventType::KeyPressed:
			this->handleKeyboard(msf::Keyboard(event->key.code), true);
			break;
		case sf::Event::EventType::KeyReleased:
			this->handleKeyboard(msf::Keyboard(event->key.code), false);
			break;
		case sf::Event::MouseButtonPressed:
			this->handleMouse(msf::Button(event->mouseButton.button), true);
			break;
		case sf::Event::MouseButtonReleased:
			this->handleMouse(msf::Button(event->mouseButton.button), false);
			break;
		default:
			break;
	}

}

void Game::handleEvents() {
	// test -> keyboard;
	/*if (keyboard.isKeyPressedComplex(msf::Keyboard::LControl, msf::Keyboard::A)) {
		std::cout << "Press Control + A" << std::endl;
	}*/
	/*if (keyboard.isKeyPressed(msf::Keyboard::A)) {
		std::cout << "Press A" << std::endl;
	}*/
	//if (keyboard.isKeyPressedComplexOne(msf::Keyboard::LControl, msf::Keyboard::A)) {
	//	std::cout << "Press one control + A" << std::endl;
	//}

	//test -> mouse 


	
	/*if (mouse.isKeyPressedAndPressed(msf::Keyboard::LControl, msf::Button::Left)) {
		std::cout << "Press Mouse :Control + left" << std::endl;
	}*/
	if (mouse.isKeyPressedAndMoveCursor(msf::Keyboard::LControl, msf::Button::Left)) {
		std::cout << "Move" << std::endl;
	}
	/*if (mouse.doubleClick(msf::Button::Left)) {
		std::cout << "Double click : left" << std::endl;
	}*/
	/*if (mouse.isButtonPressedOne(msf::Button::Left)) {
		std::cout << "Press Mouse : left" << std::endl;
	}*/
	//if (mouse.isKeyPressedAndClick(msf::Keyboard::LControl, msf::Button::Left)) {
	//	std::cout << "Press Mouse click :Control + left" << std::endl;
	//}

	//if (mouse.isButtonClicked(msf::Button::Left)) {
	//	std::cout << "Button click Left" << std::endl;
	//}


	/*

	if (mouse.isKeyPressedAndClick(msf::Button::Right, msf::Keyboard::LControl)) {
		std::cout << "Press Mouse :Control + right" << std::endl;
	}
	else if (mouse.isButtonPressedOne(msf::Button::Right)) {
		std::cout << "Press Mouse : right" << std::endl;
	}*/

}

void Game::run() {
	while (window.isOpen()) {

		sf::Event event;

		keyboard.resetPress();
		mouse.resetClick();

		while (window.pollEvent(event)) {
			this->handleInput(&event);

		}
		this->process();
		this->update();
		this->draw();
	}
}

void Game::update() {
}

void Game::process() {
	mouse.handleBeforeProcess();
	this->handleEvents();
	mouse.handleAfterProcess();
}

void Game::draw() {
	window.clear();


	window.display();
}
