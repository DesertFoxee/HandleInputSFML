#include "Random.h"


float Random::floatUniform(float min, float max) {
	std::random_device dv;
	std::mt19937 rd(dv());
	std::uniform_real_distribution<float> dist(min, max);
	return dist(rd);
}

int Random::intUniform(int min, int max) {
	std::random_device dv;
	std::mt19937 rd(dv());
	std::uniform_int_distribution<> dis(min, max);
	return dis(rd);
}

template <typename T>
T Random::normal(T min, T max) {
	if (std::is_same<int, T>::value || std::is_same<float, T>::value ||
		std::is_same<double, T>::value) {
		std::random_device dv;
		std::mt19937 rd(dv());
		std::normal_distribution<> dis((max + min) / 2, (max - min) / 2);
		return (T)dis(rd);
	}
	return (T)0;
}

template int Random::normal<int>(int, int);
template float Random::normal<float>(float, float);
template double Random::normal<double>(double, double);