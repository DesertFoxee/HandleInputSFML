#ifndef M_KEYBOARD_H
#define M_KEYBOARD_H

#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>
#include "m_baseinput.h"





class m_keyboard :public m_baseinput
{
private:
	bool is_pressed_one;
	bool is_press;
	bool is_released;
	msf::Keyboard key_old;
	msf::Keyboard key_released;

protected:
	bool isPressed(msf::Keyboard keyboard);
	bool isPressedOne(msf::Keyboard keyboard);

public:
	m_keyboard();
	~m_keyboard();

	// function often use
	void setKey(msf::Keyboard keyboard, bool state);
	bool isKeyPressed(msf::Keyboard keyboard);
	bool isKeyPressedOne(msf::Keyboard keyboard);
	template<typename ...Types>
	bool isKeyPressedComplex(msf::Keyboard key_first , Types ...key_rest , msf::Keyboard key_end);
	template<typename ...Types>
	bool isKeyPressedComplexOne(msf::Keyboard key_first, Types ...key_rest, msf::Keyboard key_end);
	bool isKeyReleased(msf::Keyboard keyboard);

	//using for keyboard one click
	void resetPress();
};

#endif // !M_KEYBOARD_H

template<typename ...Types>
inline bool m_keyboard::isKeyPressedComplex(msf::Keyboard key_first, Types ...key_rest, msf::Keyboard key_end) {

	return (this->isPressed(key_end) && m_baseinput::pressKeyComplex(key_first , key_rest..., key_end) );
}

template<typename ...Types>
inline bool m_keyboard::isKeyPressedComplexOne(msf::Keyboard key_first, Types ...key_rest, msf::Keyboard key_end) {
	return (this->isPressedOne(key_end) && m_baseinput::pressKeyComplex(key_first, key_rest..., key_end));
}
