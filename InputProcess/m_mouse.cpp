#include "m_mouse.h"



m_mouse::m_mouse() :is_pressed(false), is_released(false), is_scroll(false),
btn_double_click(msf::Button::ButtonCount), is_double_click(false),
btn_released(msf::Button::ButtonCount), btn_click(msf::Button::ButtonCount) {
	mouse_zoom = 0;
	btn_state = msf::ButtonState::None;
	is_clicked = false;
	btn_pressed = msf::Button::ButtonCount;
	clock_double.restart();
	state_click = 0;
	have_click = false;
	is_pressed_one = false;
	btn_old = msf::Button::ButtonCount;
}

m_mouse::~m_mouse() {
}

sf::Vector2i m_mouse::getCursorPos(const sf::Window& window) {
	return sf::Mouse::getPosition(window);
}

sf::Vector2i m_mouse::getCursorPos() {
	return sf::Mouse::getPosition();
}

void m_mouse::setCursorPos(const sf::Window& window, const sf::Vector2i& pos) {
	sf::Mouse::setPosition(pos, window);
}

void m_mouse::setCursorPos(const sf::Vector2i& pos) {
	sf::Mouse::setPosition(pos);
}

void m_mouse::zoom(int delta) {
	mouse_zoom += delta;
	if (mouse_zoom < MIN_ZOOM) mouse_zoom = MIN_ZOOM;
	else if (mouse_zoom > MAX_ZOOM) mouse_zoom = MAX_ZOOM;
}


void m_mouse::resetClick() {
	if (is_pressed) is_pressed = false;
	if (is_double_click) {
		state_click = 0;
		is_double_click = false;
	}
	if (is_released) is_released = false;
	if (is_clicked) {
		is_clicked = false;
		btn_state = msf::ButtonState::None;
		state_click = 0;
	}
	if (is_pressed_one) is_pressed_one = false;
}

void m_mouse::resetScroll() {
	if (this->is_scroll) is_scroll = false;
}

bool m_mouse::isScroll() {
	return false;
}

void m_mouse::setButton(msf::Button button, bool state) {

	if (state == true) {
		if (state_click == 0) {
			clock_double.restart();
			btn_state = msf::ButtonState::Pressed;
			btn_click = button;
			btn_double_click = button;
			btn_pressed = button;
			state_click++;
		}
		else if (state_click == 1) {
			sf::Time eslapsed = clock_double.getElapsedTime();
			if (button == btn_double_click && eslapsed.asMilliseconds() <=TIME_DOUBLECLICK_DELAY) {
				is_double_click = true;
				have_click = false;
				state_click = 0;
			}
		}
		if (btn_old != button) {
			is_pressed_one = true;
			btn_old = button;
		}
	}
	else {
		if (btn_click == button && btn_state == msf::ButtonState::Pressed 
			&& have_click ==false && state_click ==1 ) {
			have_click = true;
		}
		if (is_released == false) {
			this->is_released = true;
			btn_released = button;
		}
		is_pressed_one = false;
		btn_old = msf::Button::ButtonCount;
	}
	if (have_click ==false || is_double_click ==true) {
		this->setMouseComplex(button, state);
		m_baseinput::setDevice(msf::Device::mouse, mouse_complex.size() > 0);
	}
}


void m_mouse::handleBeforeProcess() {
	sf::Time eslapsed = clock_double.getElapsedTime();
	if (state_click == 1) {
		if (eslapsed.asMilliseconds() > TIME_DOUBLECLICK_DELAY) {
			is_pressed = true;
		}
	}
	if (have_click == true && eslapsed.asMilliseconds() > TIME_DOUBLECLICK_DELAY) {
		is_clicked = true;
		have_click = false;
	}
}

void m_mouse::handleAfterProcess() {
	if (is_clicked ==true) {
		this->setMouseComplex(btn_click, false);
		m_baseinput::setDevice(msf::Device::mouse, mouse_complex.size() > 0);
	}
}

bool m_mouse::isPressed(msf::Button button) {
	return (is_pressed && button ==btn_pressed);
}

bool m_mouse::isPressedOne(msf::Button button) {
	return (is_pressed_one && button == btn_pressed);
}

bool m_mouse::isButtonPressed(msf::Button button) {
	return (is_pressed && m_baseinput::pressButtonOne(button));
}

bool m_mouse::isButtonPressedOne(msf::Button button) {
	return (is_pressed_one && m_baseinput::pressButtonOne(button));
}

bool m_mouse::isButtonReleased(msf::Button button) {
	return (is_released && btn_released == button);
}

bool m_mouse::isButtonClicked(msf::Button button) {
	return (is_clicked && pressButtonOne(button));
}

bool m_mouse::doubleClick(msf::Button button) {
	return (is_double_click && btn_double_click == button);
}

bool m_mouse::isClicked(msf::Button button) {
	return (is_clicked && btn_click ==button);
}

