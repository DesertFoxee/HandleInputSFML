#include "m_keyboard.h"

m_keyboard::m_keyboard(): key_released(msf::Keyboard::Unknown) {
	this->is_press = false;
	this->is_released = false;
	this->is_pressed_one = false;
	this->key_old = msf::Keyboard::Unknown;
}

m_keyboard::~m_keyboard() {
}

void m_keyboard::setKey(msf::Keyboard keyboard, bool state) {

	this->setKeyComplex(keyboard, state);

	if (state == false) {
		if (is_released == false) is_released = true;
		key_released = keyboard;
		key_old = msf::Keyboard::Unknown;
		is_pressed_one = false;
	}
	else {
		if (key_old != keyboard) {
			is_pressed_one = true;
			key_old = keyboard;
		}
		if (is_press == false) is_press = true;
	}
	m_baseinput::setDevice(msf::Device::keyboard, key_complex.size() > 0);
}


bool m_keyboard::isKeyPressed(msf::Keyboard keyboard) {
	return (is_press && m_baseinput::pressKeyOne(keyboard));
}

bool m_keyboard::isKeyPressedOne(msf::Keyboard keyboard) {
	return (is_pressed_one && m_baseinput::pressKeyOne(keyboard));
}

bool m_keyboard::isPressed(msf::Keyboard keyboard) {
	return (is_press && sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(keyboard)));
}

bool m_keyboard::isPressedOne(msf::Keyboard keyboard) {
	
	return (is_pressed_one && sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(keyboard)));
}


bool m_keyboard::isKeyReleased(msf::Keyboard keyboard) {
	return (is_released && key_released == keyboard);
}

void m_keyboard::resetPress() {
	if (is_press) is_press = false;
	if (is_released) is_released = false;
	if (is_pressed_one) is_pressed_one = false;
}


