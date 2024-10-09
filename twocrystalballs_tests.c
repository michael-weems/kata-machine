#include <stdio.h>
#include <stdbool.h>
#include "_tests.h"
#include "twocrystalballs.h"

int main(int argc, char *argv[]) { 

	int tests = 0;
	int errors = 0;	
	
	//////////////////////////////////////////////////////
	// 10 floors
	int floors = 10;
	bool a_in[floors]; 
	int a_ex = 5;
	int i;
	for (i = 0; i < a_ex; ++i) {
		a_in[i] = false;
	}
	for (; i < floors; ++i) {
		a_in[i] = true;
	}

	int a_re = twocrystalballs(a_in, floors);

	if (a_ex == a_re) {
		char buffer[100];
		sprintf(buffer, "%d floors", floors);
		pass(buffer);
	} else {
		errors += failInt(a_ex, a_re);
	}
	++tests;

	//////////////////////////////////////////////////////
	// 100 floors
	floors = 100;
	bool b_in[floors];
	int b_ex = 62;
	for (i = 0; i < b_ex; ++i) {
		b_in[i] = false;
	}
	for (; i < floors; ++i) {
		b_in[i] = true;
	}

	int b_re = twocrystalballs(b_in, floors);

	if (b_ex == b_re) {
		char buffer[100];
		sprintf(buffer, "%d floors", floors);
		pass(buffer);
	} else {
		errors += failInt(b_ex, b_re);
	}
	++tests;

	summary(errors, tests);
	return 0;
}

