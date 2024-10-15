#include <stdio.h>
#include "singlylinkedlist.h"
#include "_testutils.h"

int main(int argc, char *argv[]) { 
	int tests = 0;
	int errors = 0;	

	struct sll_t *list = sll_create();

	int n = 25;
	int a[25] = {5000, 10, 20, 90, 30, 40, 6000, 50, 25, 15, 5, 900, 45, 35, 100, 60, 75, 80, 55, 500, 85, 300, 250, 330, 3500};

	for (int i = 0; i < n; ++i) {
		sll_insert(list, a[i]);
	}

	int before = errors;
	for (int i=0; i < n; ++i) {
		bool contains = sll_contains(list, a[i]);
		if (contains == false) {
			errors += 1;
		}
		++tests;
	}
	if (errors - before == 0) {
		pass("found all inserted values");
	} else {
		char msg[200];
		sprintf(msg, "didn't find %d out of %d total values", errors - before, n);
		fail(msg);
	}
	before = errors;
	
	int x = 10;
	int y[10] = {9922, 20000, 41234, 333, 123, 4499, 8999, 4321, 32864, 87777};
	for (int i=0; i < x; ++i){
		bool contains = sll_contains(list, y[i]);
		if (contains) {
			errors += 1; 
		}
		++tests;
	}
	if (errors - before == 0) {
		pass("found no non-existent values");
	} else {
		char msg[200];
		sprintf(msg, "found %d out of %d items that didn't exist", errors - before, x);
		fail(msg);
	}

	int dMin = 7; 
	int dMax = 17; 

	before = errors;
	for (int i = dMin; i <= dMax; ++i) {
		bool removed = sll_remove(list, a[i]);
		if (removed == false) {
			errors += 1; 
		}
		++tests;
	}
	if (errors - before == 0) {
		pass("deleted requested values");
	} else {
		char msg[200];
		sprintf(msg, "could not remove %d out of %d items", errors - before, dMax - dMin);
		fail(msg);
	}

	before = errors;
	int i = 0;
	for (; i < dMin; ++i) {
		bool contains = sll_contains(list, a[i]);
		if (!contains) {
			errors += 1;
		}
		++tests;
	}
	if (errors - before == 0) {
		pass("existing items still exist");
	} else {
		char msg[200];
		sprintf(msg, "%d errors checking if items still exist", errors - before);
		fail(msg);
	}
	
	before = errors;
	for (; i <= dMax; ++i) {
		bool contains = sll_contains(list, a[i]);
		if (contains) {
			errors += 1;
		}
		++tests;
	}
	if (errors - before == 0) {
		pass("did not find deleted items");
	} else {
		char msg[200];
		sprintf(msg, "%d deleted items still found", errors - before);
		fail(msg);
	}
	
	before = errors;
	for (; i < n; ++i) {
		bool contains = sll_contains(list, a[i]);
		if (!contains) {
			errors += 1;
		}
		++tests;
	}
	if (errors - before == 0) {
		pass("existing items still exist");
	} else {
		char msg[200];
		sprintf(msg, "%d errors checking if items still exist", errors - before);
		fail(msg);
	}

	for (int i = dMin; i <= dMax; ++i) {
		sll_insert(list, a[i]);
	}

	before = errors;
	for (int i=0; i < n; ++i) {
		bool contains = sll_contains(list, a[i]);
		if (!contains) {
			errors += 1;
		}
		++tests;
	}
	if (errors - before == 0) {
		pass("found all items, including re-inserted items");
	} else {
		char msg[200];
		sprintf(msg, "%d errors when checking for re-inserted items", errors - before);
		fail(msg);
	}


	int length = sll_length(list);
	if (length == n) {
		pass("successfully determined length");
	} else {
		fail("incorrect length");
		errors++;
	}
	++tests;

	sll_reverse(list);
	length = sll_length(list);
	if (length == n) {
		pass("length is still the same after reversing");
	} else {
		fail("length changed upon reversing");
		errors++;
	}
	++tests;

	before = errors;
	for (int i=0; i < n; ++i) {
		int value = sll_get(list, i);
		if (value != a[n-i-1]) {
			errors += 1;
		}
		++tests;
	}
	if (errors - before == 0) {
		pass("reversed array contains all elements in correct order");
	} else {
		char msg[200];
		sprintf(msg, "%d elements not in right place after reverse", errors - before);
		fail(msg);
	}

	sll_destroy(list);
	list = sll_create();
	for (int i = 0; i < n; ++i) {
		sll_insert(list, a[i]);
	}

	int removed = sll_remove_at(list, 10);
	if (removed == a[10]) {
		pass("removed correct element");
	} else {
		char msg[200];
		sprintf(msg, "%d removed, expected %d", removed, a[10]);
		fail(msg);
		errors++;
	}
	tests++;
	removed = sll_remove_at(list, 10);
	if (removed == a[11]) {
		pass("removed correct element");
	} else {
		char msg[200];
		sprintf(msg, "%d removed, expected %d", removed, a[11]);
		fail(msg);
		errors++;
	}
	tests++;
	removed = sll_remove_at(list, 10);
	if (removed == a[12]) {
		pass("removed correct element");
	} else {
		char msg[200];
		sprintf(msg, "%d removed, expected %d", removed, a[12]);
		fail(msg);
		errors++;
	}
	tests++;
	removed = sll_remove_at(list, 0);
	if (removed == a[0]) {
		pass("removed correct element");
	} else {
		char msg[200];
		sprintf(msg, "%d removed, expected %d", removed, a[0]);
		fail(msg);
		errors++;
	}
	tests++;

	sll_destroy(list);
	
	summary(errors, tests);
	return errors > 0 ? 1 : 0;

}

