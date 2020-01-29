#ifndef EXTENDVECTOR2F_H
#define EXTENDVECTOR2F_H

#include <SFML/Graphics.hpp>
#include "Random.h"

class Vector2F
{
public :
	static sf::Vector2f normalize(const sf::Vector2f& vec);
	static float mag(const sf::Vector2f& vec);
	static float angle(const sf::Vector2f& vec);
	static float angleBetween(const sf::Vector2f& vec1, const sf::Vector2f& vec2);
	static sf::Vector2f rotate(const sf::Vector2f& vec ,float angleR);
	static sf::Vector2f move(const sf::Vector2f& vec ,float angleR , float distance);
	static void limit(sf::Vector2f& vec , const sf::Vector2f& vec_limit);
	static sf::Vector2f ramdom(float min , float max);
};


#endif // !EXTENDVECTOR2F_H



