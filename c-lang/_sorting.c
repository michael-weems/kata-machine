#include <string.h>
#include "_sorting.h"
#include "_testutils.h"
#include "bubblesort.h"
#include "heapsort.h"
#include "insertionsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include "selectionsort.h"

SortStrategy sortFactory(char *strategy) {
	if (strcmp(strategy, "bubblesort") == 0) {
		return &bubblesort;
	}
	if (strcmp(strategy, "heapsort") == 0) {
		return &heapsort;
	}
	if (strcmp(strategy, "insertionsort") == 0) {
		return &insertionsort;
	}
	if (strcmp(strategy, "mergesort") == 0) {
		return &mergesort;
	}
	if (strcmp(strategy, "quicksort") == 0) {
		return &quicksort;
	}
	if (strcmp(strategy, "selectionsort") == 0) {
		return &selectionsort;
	}

	printf("error: strategy not recognized (%s)\n", strategy);
	exit(1);
}

int sortingTests(char *sortingStrategy) {
	SortStrategy sort = sortFactory(sortingStrategy);

	bool failed = false; 
	int tests = 0;
	int errors = 0;	
	
	//////////////////////////////////////////////////////
	// sort non-sorted array
	int a_in[10] = {4,2,10,3,9,1,8,5,7,6};
	int a_re[10] = {4,2,10,3,9,1,8,5,7,6};
	int a_ex[10] = {1,2,3,4,5,6,7,8,9,10};

	sort(a_re, 10);

	for (int i = 0; i < 10; ++i){
		if (a_re[i] != a_ex[i]) {
			errors += failArray(a_in, a_ex, a_re);
			failed = true;
			break;
		}
	}
	if (!failed) {
		pass("sort all-unique, non-sorted array");
	}
	failed = false;
	++tests;
	
	//////////////////////////////////////////////////////
	// sort already sorted array
	int c_in[10] = {1,2,3,4,5,6,7,8,9,10};
	int c_re[10] = {1,2,3,4,5,6,7,8,9,10};
	int c_ex[10] = {1,2,3,4,5,6,7,8,9,10};

	sort(c_re, 10);

	for (int i = 0; i < 10; ++i){
		if (c_re[i] != c_ex[i]) {
			errors += failArray(c_in, c_ex, c_re);
			failed = true;
			break;
		}
	}
	if (!failed) {
		pass("sort already sorted array");
	}
	failed = false;
	++tests;

	//////////////////////////////////////////////////////
	// sort reverse sorted array
	int d_in[10] = {10,9,8,7,6,5,4,3,2,1};
	int d_re[10] = {10,9,8,7,6,5,4,3,2,1};
	int d_ex[10] = {1,2,3,4,5,6,7,8,9,10};

	sort(d_re, 10);

	for (int i = 0; i < 10; ++i){
		if (d_re[i] != d_ex[i]) {
			errors += failArray(d_in, d_ex, d_re);
			failed = true;
			break;
		}
	}
	if (!failed) {
		pass("sort already sorted array");
	}
	failed = false;
	++tests;

	summary(errors, tests);
	return errors > 0 ? 1 : 0;
}

