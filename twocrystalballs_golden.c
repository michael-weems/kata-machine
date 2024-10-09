#include "twocrystalballs.h"
#include <math.h>

int twocrystalballs(bool *floors, int floorsSize) {
	double interval = sqrt(floorsSize);

	int i;
	for (i = 0; i < floorsSize; i += interval) {
		if (floors[i]){
			i -= interval;
			break;
		}
	}

	for (; i < floorsSize; ++i) {
		if (floors[i]) {
			return i;
		}
	}

	return -1;
}
