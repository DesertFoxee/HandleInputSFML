#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>

class Object
{

protected:
	sf::Vector2f loc;
	sf::Vector2f vec;
	sf::Vector2f acc;
public:
	Object() {
		this->loc = sf::Vector2f(0, 0);
		this->vec = sf::Vector2f(0, 0);
		this->acc = sf::Vector2f(0, 0);
	};
	Object(sf::Vector2f loc, sf::Vector2f vec , sf::Vector2f acc = sf::Vector2f(0, 0)) {
		this->loc = loc;
		this->vec = vec;
		this->acc = acc;
	};
};


#endif // !OBJECT_H


