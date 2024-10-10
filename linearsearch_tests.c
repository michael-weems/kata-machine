#include <stdio.h>
#include <stdbool.h>
#include "_testutils.h"
#include "linearsearch.h"

int main(int argc, char *argv[]) { 

	int tests = 0;
	int errors = 0;	
	
	//////////////////////////////////////////////////////
	// find needle in size 10 array
	int a_haystack[10] = {4,2,10,3,9,1,8,5,7,6};
	int a_needle = 8;
	bool a_ex = true;
	bool a_re = linearsearch(a_haystack, 10, a_needle);

	if (a_ex == a_re) {
		pass("found needle");
	} else {
		errors += failBool(a_ex, a_re);
	}
	++tests;
	
	//////////////////////////////////////////////////////
	// find no needle
	int b_haystack[10] = {4,2,10,3,9,1,8,5,7,6};
	int b_needle = 40;
	bool b_ex = false;
	bool b_re = linearsearch(b_haystack, 10, b_needle);

	if (b_ex == b_re) {
		pass("no needle to find");
	} else {
		errors += failBool(b_ex, b_re);
	}
	++tests;
	
	//////////////////////////////////////////////////////
	// find needle in size 100 array
	int c_haystack[100];
	for (int i = 0; i < 100; ++i) {
		c_haystack[i] = i;
	}
	int c_needle = 82;
	bool c_ex = true;
	bool c_re = linearsearch(c_haystack, 100, c_needle);

	if (c_ex == c_re) {
		pass("found needle in 100 size haystack");
	} else {
		errors += failBool(c_ex, c_re);
	}
	++tests;
	
	//////////////////////////////////////////////////////
	// don't find needle in size 100 array
	int d_needle = 900;
	bool d_ex = false;
	bool d_re = linearsearch(c_haystack, 100, d_needle);

	if (d_ex == d_re) {
		pass("didn't find needle in 100 size haystack");
	} else {
		errors += failBool(d_ex, d_re);
	}
	++tests;

	summary(errors, tests);
	return errors > 0 ? 1 : 0;
}

