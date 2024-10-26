#include "selectionsort.h"

void selectionsort(int *arr, int arrSize) {
	for (int i = 0; i < arrSize; ++i) {
		int lowest = i;
		for (int j = i; j < arrSize; ++j) {
			if (arr[j] < arr[lowest]) {
				lowest = j;
			}
		}

		int tmp = arr[i];
		arr[i] = arr[lowest];
		arr[lowest] = tmp;
	}
}
