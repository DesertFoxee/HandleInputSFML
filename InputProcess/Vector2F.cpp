#include "Vector2F.h"

sf::Vector2f Vector2F::normalize(const sf::Vector2f& vec) {
	float mag = Vector2F::mag(vec);

	if (mag != 0) {
		return sf::Vector2f(vec / mag);
	}
	return sf::Vector2f(0, 0);
}

float Vector2F::mag(const sf::Vector2f& vec) {
	return sqrtf(vec.x * vec.x + vec.y * vec.y);
}

float Vector2F::angle(const sf::Vector2f& vec) {
	return atan2f(vec.y, vec.x);
}

float Vector2F::angleBetween(const sf::Vector2f& vec1, const sf::Vector2f& vec2) {
	float dot = vec1.x * vec2.x + vec1.y * vec2.y;
	float mag = Vector2F::mag(vec1) * Vector2F::mag(vec2);

	return (mag != 0) ? acosf(dot / mag) : 0.f;

}

sf::Vector2f Vector2F::rotate(const sf::Vector2f& vec, float angleR) {
	sf::Vector2f r_vec;
	r_vec.x = cosf(angleR) * vec.x - sinf(angleR) * vec.y;
	r_vec.y = sinf(angleR) * vec.x + cos(angleR) * vec.y;
	return r_vec;
}

sf::Vector2f Vector2F::move(const sf::Vector2f& vec, float angleR, float distance) {
	sf::Vector2f point_move;
	point_move.x = vec.x + cosf(angleR) * distance;
	point_move.y = vec.y + sinf(angleR) * distance;
	return point_move;
}

void Vector2F::limit(sf::Vector2f& vec, const sf::Vector2f& vec_limit) {
	vec.x = (vec.x <= vec_limit.x) ? vec.x : vec_limit.x;
	vec.y = (vec.y <= vec_limit.y) ? vec.y : vec_limit.y;
}

sf::Vector2f Vector2F::ramdom(float min, float max) {
	sf::Vector2f vec;

	vec.x = Random::floatUniform(min, max);
	vec.y = Random::floatUniform(min, max);
	return vec;

}
