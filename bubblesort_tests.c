#include <stdio.h>
#include <stdbool.h>
#include "_tests.h"
#include "bubblesort.h"

int main(int argc, char *argv[]) { 

	bool failed = false; 
	int tests = 0;
	int errors = 0;	
	
	//////////////////////////////////////////////////////
	// sort all-unique, non-sorted array
	int a_in[10] = {4,2,10,3,9,1,8,5,7,6};
	int a_re[10] = {4,2,10,3,9,1,8,5,7,6};
	int a_ex[10] = {1,2,3,4,5,6,7,8,9,10};

	bubblesort(a_re, 10);

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
	// sort non-unique, non-sorted array
	int b_in[10] = {4,2,10,3,4,4,8,5,7,6};
	int b_re[10] = {4,2,10,3,4,4,8,5,7,6};
	int b_ex[10] = {2,3,4,4,4,5,6,7,8,10};

	bubblesort(b_re, 10);

	for (int i = 0; i < 10; ++i){
		if (b_re[i] != b_ex[i]) {
			errors += failArray(b_in, b_ex, b_re);
			failed = true;
			break;
		}
	}
	if (!failed) {
		pass("sort non-unique, non-sorted array");
	}
	failed = false;
	++tests;

	//////////////////////////////////////////////////////
	// sort already sorted array
	int c_in[10] = {1,2,3,4,5,6,7,8,9,10};
	int c_re[10] = {1,2,3,4,5,6,7,8,9,10};
	int c_ex[10] = {1,2,3,4,5,6,7,8,9,10};

	bubblesort(c_re, 10);

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

	bubblesort(d_re, 10);

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

	return 0;
}

