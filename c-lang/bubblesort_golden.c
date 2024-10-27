#include "bubblesort.h"

void bubblesort(int *arr, int arrSize) {
	for (int i = 1; i < arrSize; ++i) {
		for (int j = 1; j < arrSize; ++j) {
			if (arr[j] < arr[j-1]) {
				int tmp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}
