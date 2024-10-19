#include <stdio.h>
#include "doublylinkedlist.h"
#include "_testutils.h"

int main(int argc, char *argv[]) { 
	int tests = 0;
	int errors = 0;	

	struct dll_t *list = dll_create();

	int n = 25;
	int a[25] = {5000, 10, 20, 90, 30, 40, 6000, 50, 25, 15, 5, 900, 45, 35, 100, 60, 75, 80, 55, 500, 85, 300, 250, 330, 3500};

	for (int i = 0; i < n; ++i) {
		dll_append(list, a[i]);
	}

	int before = errors;
	for (int i=0; i < n; ++i) {
		bool contains = dll_contains(list, a[i]);
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
		bool contains = dll_contains(list, y[i]);
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
		bool removed = dll_remove(list, a[i]);
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
		bool contains = dll_contains(list, a[i]);
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
		bool contains = dll_contains(list, a[i]);
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
		bool contains = dll_contains(list, a[i]);
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
		dll_append(list, a[i]);
	}

	before = errors;
	for (int i=0; i < n; ++i) {
		bool contains = dll_contains(list, a[i]);
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


	int length = dll_length(list);
	if (length == n) {
		pass("successfully determined length");
	} else {
		fail("incorrect length");
		errors++;
	}
	++tests;

	dll_destroy(list);
	list = dll_create();
	for (int i = 0; i < n; ++i) {
		dll_append(list, a[i]);
	}

	//{5000, 10, 20, 90, 30, 40, 6000, 50, 25, 15, 5, 900, 45, 35, 100, 60, 75, 80, 55, 500, 85, 300, 250, 330, 3500};
	int removed = dll_remove_at(list, 10);
	if (removed == a[10]) {
		pass("removed correct element");
	} else {
		char msg[200];
		sprintf(msg, "%d removed, expected %d", removed, a[10]);
		fail(msg);
		errors++;
	}
	tests++;
	removed = dll_remove_at(list, 10);
	if (removed == a[11]) {
		pass("removed correct element");
	} else {
		char msg[200];
		sprintf(msg, "%d removed, expected %d", removed, a[11]);
		fail(msg);
		errors++;
	}
	tests++;
	removed = dll_remove_at(list, 10);
	if (removed == a[12]) {
		pass("removed correct element");
	} else {
		char msg[200];
		sprintf(msg, "%d removed, expected %d", removed, a[12]);
		fail(msg);
		errors++;
	}
	tests++;
	removed = dll_remove_at(list, 0);
	if (removed == a[0]) {
		pass("removed correct element");
	} else {
		char msg[200];
		sprintf(msg, "%d removed, expected %d", removed, a[0]);
		fail(msg);
		errors++;
	}
	tests++;

	dll_prepend(list, 4);
	dll_prepend(list, 3);
	dll_prepend(list, 2);
	dll_prepend(list, 1);
	int val = dll_get(list, 0);
	if (val == 1) {
		pass("prepended 1 correctly");
	} else {
		char msg[200];
		sprintf(msg, "%d found, expected %d", val, 1);
		fail(msg);
		errors++;
	}
	++tests;
	val = dll_get(list, 1);
	if (val == 2) {
		pass("prepended 2 correctly");
	} else {
		char msg[200];
		sprintf(msg, "%d found, expected %d", val, 2);
		fail(msg);
		errors++;
	}
	++tests;
	val = dll_get(list, 2);
	if (val == 3) {
		pass("prepended 3 correctly");
	} else {
		char msg[200];
		sprintf(msg, "%d found, expected %d", val, 3);
		fail(msg);
		errors++;
	}
	++tests;
	val = dll_get(list, 3);
	if (val == 4) {
		pass("prepended 4 correctly");
	} else {
		char msg[200];
		sprintf(msg, "%d found, expected %d", val, 4);
		fail(msg);
		errors++;
	}
	++tests;

	dll_insert(list, 3, 999);
	val = dll_get(list, 3);
	if (val == 999) {
		pass("inserted 999 correctly");
	} else {
		char msg[200];
		sprintf(msg, "%d found, expected %d", val, 999);
		fail(msg);
		errors++;
	}
	++tests;

	dll_insert(list, 10, 888);
	val = dll_get(list, 10);
	if (val == 888) {
		pass("inserted 888 correctly");
	} else {
		char msg[200];
		sprintf(msg, "%d found, expected %d", val, 888);
		fail(msg);
		errors++;
	}
	++tests;

	dll_insert(list, 14, 111);
	val = dll_get(list, 14);
	if (val == 111) {
		pass("inserted 111 correctly");
	} else {
		char msg[200];
		sprintf(msg, "%d found, expected %d", val, 111);
		fail(msg);
		errors++;
	}
	++tests;

	dll_destroy(list);
	
	summary(errors, tests);
	return errors > 0 ? 1 : 0;

}

