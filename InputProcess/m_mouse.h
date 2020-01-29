#ifndef M_MOUSE_H
#define M_MOUSE_H


#include <memory>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>
#include "m_baseinput.h"

#define MIN_ZOOM 1

#define MAX_ZOOM 20

#define TIME_DOUBLECLICK_DELAY 190





class m_mouse : public m_baseinput
{
private:
	bool is_clicked;
	bool is_pressed;
	bool is_pressed_one;
	bool is_released;
	bool is_scroll;
	bool is_double_click;
	bool have_click;
	int state_click;


	int mouse_zoom;
	sf::Clock clock_double;
	msf::Button btn_double_click;
	msf::Button btn_released;
	msf::Button btn_click;
	msf::Button btn_pressed;
	msf::ButtonState btn_state;
	msf::Button btn_old;

private :
	bool isPressed(msf::Button button);
	bool isPressedOne(msf::Button button);

public:
	m_mouse();
	~m_mouse();

	//screen
	sf::Vector2i getCursorPos(const sf::Window& window);
	sf::Vector2i getCursorPos();
	void setCursorPos(const sf::Window& window, const sf::Vector2i& pos);
	void setCursorPos(const sf::Vector2i& pos);

	// function check;
	bool isScroll();

	// function process;
	void zoom(int delta = 1);
	void handleBeforeProcess();
	void handleAfterProcess();

	// function set value 
	void setScroll(bool state) { is_scroll = state; };
	void setButton(msf::Button button, bool state);

	// function remove or reset value
	void resetClick();
	void resetZoom() { mouse_zoom = MIN_ZOOM; }
	void resetScroll();


	// event function often used 
	int getZoom() { return m_mouse::mouse_zoom; };
	bool isButtonPressed(msf::Button button);
	bool isButtonPressedOne(msf::Button button);
	bool isButtonReleased(msf::Button button);
	bool isButtonClicked(msf::Button button);
	template<typename... Types>
	bool isKeyPressedAndClick(msf::Keyboard key_first, Types ...key_rest, msf::Button mousekey);

	template<typename... Types>
	bool isKeyPressedAndPressed(msf::Keyboard key_first, Types ...key_rest, msf::Button mousekey);
	bool doubleClick(msf::Button button);
	bool isClicked(msf::Button button);

	template<typename... Types>
	bool isKeyPressedAndMoveCursor(msf::Keyboard key_first, Types ...key_rest, msf::Button mousekey);

};


#endif // !M_MOUSE_H

template<typename ...Types>
inline bool m_mouse::isKeyPressedAndClick(msf::Keyboard key_first, Types ...key_rest, msf::Button mousekey) {
	if (m_baseinput::checkOrderDevice(msf::Device::keyboard, msf::Device::mouse)) {
		if (m_baseinput::pressKeyComplex(key_first ,key_rest...) && this->isClicked(mousekey)) {
			return true;
		}
	}
	return false;
}

template<typename ...Types>
inline bool m_mouse::isKeyPressedAndPressed(msf::Keyboard key_first, Types ...key_rest, msf::Button mousekey) {
	if (m_baseinput::checkOrderDevice(msf::Device::keyboard, msf::Device::mouse)) {
	
		if (m_baseinput::pressKeyComplex(key_first , key_rest...) &&
				this->isPressedOne(mousekey) ){
			return true;
		}
	}
	return false;
}

template<typename ...Types>
inline bool m_mouse::isKeyPressedAndMoveCursor(msf::Keyboard key_first, Types ...key_rest, msf::Button mousekey) {
	if (m_baseinput::checkOrderDevice(msf::Device::keyboard, msf::Device::mouse)) {
		if (m_baseinput::pressKeyComplex(key_first , key_rest...) 
				&& this->isPressed(mousekey)) {
			return true;
		}
	}
	return false;
}



