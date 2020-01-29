#include "m_baseinput.h"

std::vector<msf::Keyboard> m_baseinput::key_user;
std::vector<msf::Button> m_baseinput::mouse_complex;
std::vector<msf::Device > m_baseinput::device_user;
std::vector<msf::Device> m_baseinput::order_device;
std::vector<msf::Keyboard> m_baseinput::key_complex;


void m_baseinput::setDevice(msf::Device device, bool state) {
	if (state == false) {
		order_device.erase(std::remove(order_device.begin(), order_device.end(), device),
			order_device.end());
	}
	else {
		if (order_device.size() < MAX_DEVICE &&
			std::find(order_device.begin(), order_device.end(), device) == order_device.end()) {
			order_device.push_back(device);
		}
	}
}

void m_baseinput::setKeyComplex(msf::Keyboard keyboard, bool state) {
	if (state == false) {
		key_complex.erase(std::remove(key_complex.begin(), key_complex.end(), keyboard),
			key_complex.end());
	}
	else {
		if (key_complex.size() < MAX_KEYCOMPLEX &&
			std::find(key_complex.begin(), key_complex.end(), keyboard) == key_complex.end()) {
			key_complex.push_back(keyboard);
		}
	}
}

void m_baseinput::setMouseComplex(msf::Button button, bool state) {
	if (state == false) {
		mouse_complex.erase(std::remove(mouse_complex.begin(), mouse_complex.end(), button),
			mouse_complex.end());
	}
	else {
		if (mouse_complex.size() < MAX_MOUSECOMPLEX &&
			std::find(mouse_complex.begin(), mouse_complex.end(), button) == mouse_complex.end()) {
			mouse_complex.push_back(button);
		}
	}
}


