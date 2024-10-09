#include "quicksort.h"

int partition(int *arr, int lo, int hi) {
	int pivot = arr[hi];
	int idx = lo - 1;

	for (int i = lo; i <= hi - 1; ++i) {
		if (arr[i] < pivot) {
			++idx;
			int tmp = arr[i];
			arr[i] = arr[idx];
			arr[idx] = tmp;
		}
	}
	++idx;

	arr[hi] = arr[idx];
	arr[idx] = pivot;
	return idx;
}

void qs(int *arr, int lo, int hi) {
	if (lo >= hi) {
		return;
	}

	int p = partition(arr, lo, hi);

	qs(arr, lo, p-1);
	qs(arr, p+1, hi);
}

void quicksort(int *arr, int arrSize) {
	qs(arr, 0, arrSize - 1);
}
