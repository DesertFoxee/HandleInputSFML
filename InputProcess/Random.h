#ifndef RANDOM_H
#define RANDOM_H

#include <random>


class Random
{

public:

	static float floatUniform(float min, float max);

	static int intUniform(int min, int max);

	template <typename T>
	static T normal(T min, T max);

};



#endif // !RANDOM_H

