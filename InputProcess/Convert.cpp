#include "Convert.h"

float Convert::radiusToDegree(float angleR) {
	return angleR * float(180 / PI);
}

float Convert::degreeToRadius(float angleD) {
	return angleD * float(PI / 180);
}
