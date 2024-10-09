#include <stdio.h>
#include <stdbool.h>
#include "_tests.h"
#include "bubblesort.h"

int main(int argc, char *argv[]) { 

	// TODO: implement test cases
	bool failed = false; 
	int tests = 0;
	int errors = 0;	
	
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

	summary(errors, tests);

	return 0;
}

