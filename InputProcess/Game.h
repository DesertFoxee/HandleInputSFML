#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "m_keyboard.h"
#include "m_mouse.h"

class Game
{
private:
	sf::RenderWindow window;
	std::string title;
	unsigned int width;
	unsigned int height;
	unsigned int limit_frame;

	// input 
	static m_keyboard keyboard;
	static m_mouse mouse;

private:
	void init();
	void draw();
	void handleKeyboard(const msf::Keyboard key, bool state);
	void handleMouse(const msf::Button btn, bool state);
	void handleInput(sf::Event* event);
	void handleEvents();
	void update();
	void process();
public:
	Game(std::string title, unsigned int width, unsigned int height, unsigned int limit_frame = 0);
	void run();
};

#endif // !GAME_H
