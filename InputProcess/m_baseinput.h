#ifndef M_BASEINPUT_H
#define M_BASEINPUT_H

#include <vector>
#include <algorithm>
#include <iostream>

#define MAX_DEVICE 2

#define MAX_KEYCOMPLEX 3
#define MAX_MOUSECOMPLEX 2

namespace msf
{
	enum class Device
	{
		keyboard,
		mouse
	};
	enum class Keyboard
	{
		Unknown = -1, ///< Unhandled key
		A = 0,        ///< The A key
		B,            ///< The B key
		C,            ///< The C key
		D,            ///< The D key
		E,            ///< The E key
		F,            ///< The F key
		G,            ///< The G key
		H,            ///< The H key
		I,            ///< The I key
		J,            ///< The J key
		K,            ///< The K key
		L,            ///< The L key
		M,            ///< The M key
		N,            ///< The N key
		O,            ///< The O key
		P,            ///< The P key
		Q,            ///< The Q key
		R,            ///< The R key
		S,            ///< The S key
		T,            ///< The T key
		U,            ///< The U key
		V,            ///< The V key
		W,            ///< The W key
		X,            ///< The X key
		Y,            ///< The Y key
		Z,            ///< The Z key
		Num0,         ///< The 0 key
		Num1,         ///< The 1 key
		Num2,         ///< The 2 key
		Num3,         ///< The 3 key
		Num4,         ///< The 4 key
		Num5,         ///< The 5 key
		Num6,         ///< The 6 key
		Num7,         ///< The 7 key
		Num8,         ///< The 8 key
		Num9,         ///< The 9 key
		Escape,       ///< The Escape key
		LControl,     ///< The left Control key
		LShift,       ///< The left Shift key
		LAlt,         ///< The left Alt key
		LSystem,      ///< The left OS specific key: window (Windows and Linux), apple (MacOS X), ...
		RControl,     ///< The right Control key
		RShift,       ///< The right Shift key
		RAlt,         ///< The right Alt key
		RSystem,      ///< The right OS specific key: window (Windows and Linux), apple (MacOS X), ...
		Menu,         ///< The Menu key
		LBracket,     ///< The [ key
		RBracket,     ///< The ] key
		Semicolon,    ///< The ; key
		Comma,        ///< The , key
		Period,       ///< The . key
		Quote,        ///< The ' key
		Slash,        ///< The / key
		Backslash,    ///< The \ key
		Tilde,        ///< The ~ key
		Equal,        ///< The = key
		Hyphen,       ///< The - key (hyphen)
		Space,        ///< The Space key
		Enter,        ///< The Enter/Return keys
		Backspace,    ///< The Backspace key
		Tab,          ///< The Tabulation key
		PageUp,       ///< The Page up key
		PageDown,     ///< The Page down key
		End,          ///< The End key
		Home,         ///< The Home key
		Insert,       ///< The Insert key
		Delete,       ///< The Delete key
		Add,          ///< The + key
		Subtract,     ///< The - key (minus, usually from numpad)
		Multiply,     ///< The * key
		Divide,       ///< The / key
		Left,         ///< Left arrow
		Right,        ///< Right arrow
		Up,           ///< Up arrow
		Down,         ///< Down arrow
		Numpad0,      ///< The numpad 0 key
		Numpad1,      ///< The numpad 1 key
		Numpad2,      ///< The numpad 2 key
		Numpad3,      ///< The numpad 3 key
		Numpad4,      ///< The numpad 4 key
		Numpad5,      ///< The numpad 5 key
		Numpad6,      ///< The numpad 6 key
		Numpad7,      ///< The numpad 7 key
		Numpad8,      ///< The numpad 8 key
		Numpad9,      ///< The numpad 9 key
		F1,           ///< The F1 key
		F2,           ///< The F2 key
		F3,           ///< The F3 key
		F4,           ///< The F4 key
		F5,           ///< The F5 key
		F6,           ///< The F6 key
		F7,           ///< The F7 key
		F8,           ///< The F8 key
		F9,           ///< The F9 key
		F10,          ///< The F10 key
		F11,          ///< The F11 key
		F12,          ///< The F12 key
		F13,          ///< The F13 key
		F14,          ///< The F14 key
		F15,          ///< The F15 key
		Pause,        ///< The Pause key

		KeyCount,     ///< Keep last -- the total number of keyboard keys

		// Deprecated values:

		Dash = Hyphen,       ///< \deprecated Use Hyphen instead
		BackSpace = Backspace,    ///< \deprecated Use Backspace instead
		BackSlash = Backslash,    ///< \deprecated Use Backslash instead
		SemiColon = Semicolon,    ///< \deprecated Use Semicolon instead
		Return = Enter         ///< \deprecated Use Enter instead
	};

	enum class Button
	{
		Left,       ///< The left mouse button
		Right,      ///< The right mouse button
		Middle,     ///< The middle (wheel) mouse button
		XButton1,   ///< The first extra mouse button
		XButton2,   ///< The second extra mouse button

		ButtonCount ///< Keep last -- the total number of mouse buttons
	};

	enum class ButtonState
	{
		None,
		Pressed,
		Released
	};
	enum class Wheel
	{
		VerticalWheel,  ///< The vertical mouse wheel
		HorizontalWheel ///< The horizontal mouse wheel
	};
}


class m_baseinput
{
protected:
	static std::vector<msf::Keyboard> key_user;
	static std::vector<msf::Device> device_user;
	static std::vector<msf::Device> order_device;
	static std::vector<msf::Keyboard> key_complex;
	static std::vector<msf::Button> mouse_complex;

protected:
	template<typename T>
	static void loadArguments(std::vector<T>& vec, T key) {
		vec.push_back(key);
	}

	template<typename T, typename... Types>
	static void loadArguments(std::vector<T>& vec, T key_one, Types... key_rest) {
		vec.push_back(key_one); loadArguments(vec, key_rest...);
	}
	static void setDevice(msf::Device device, bool state);
protected:
	
	void setKeyComplex(msf::Keyboard keyboard, bool state);
	void setMouseComplex(msf::Button button, bool state);

	template<typename... Types>
	static bool checkOrderDevice(Types... order_devices) {
		m_baseinput::loadArguments(device_user, order_devices...);
		if (device_user == order_device) {
			device_user.clear();
			return true;
		}
		device_user.clear();
		return false;
	}
	static bool checkKeyPressFunction() {

		for (auto& i : key_complex) {
			if (static_cast<int>(i) >= static_cast<int>(msf::Keyboard::LControl)
				&& static_cast<int>(i) <= static_cast<int>(msf::Keyboard::RSystem))
				return true;
		}
		return false;
	}
	template<typename... Types>
	static bool pressKeyComplex(Types... key) {
		m_baseinput::loadArguments(key_user, key...);
		if (!key_complex.empty() && key_user == key_complex) {
			key_user.clear();
			return true;
		}
		key_user.clear();
		return false;
	}
	static bool pressButtonOne(msf::Button btn) {
		if (checkKeyPressFunction() == false) {
			if (!mouse_complex.empty())
				return (mouse_complex.back() ==btn);
		}
		return false;
	}
	static bool pressKeyOne(msf::Keyboard key) {
		if (checkKeyPressFunction() == false) {
			if(!key_complex.empty())
				return (key_complex.back() == key);
		}
		return false;
	}
	static void show() {
		std::cout << "Key : ";
		for (auto i : device_user) {
			std::cout << static_cast<int> (i) << " + ";
		}
		std::cout << std::endl;
	}
public:
	static void setDevice() {
		m_baseinput::setDevice(msf::Device::mouse, mouse_complex.size() > 0);
		m_baseinput::setDevice(msf::Device::keyboard, key_complex.size() > 0);
	}
};

#endif // !M_BASEINPUT_H


