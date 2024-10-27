#include "linearsearch.h"

bool linearsearch(int *arr, int arrSize) {
	for (int i = 0; i < haystackSize; ++i) {
		if (haystack[i] == needle){
			return true;
		}
	}
	return false;
}
