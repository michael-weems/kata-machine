#include <stdio.h>
#include <stdbool.h>
#include "_testutils.h"
#include "hashmap.h"

int main(int argc, char *argv[]) { 
	int tests = 0;
	int errors = 0;	

	HashMap *map = hashmap_create(10, 60);

	int n = 25;
	int a[25] = {5000, 10, 20, 90, 30, 40, 6000, 50, 25, 15, 5, 900, 45, 35, 100, 60, 75, 80, 55, 500, 85, 300, 250, 330, 3500};

	for (int i = 0; i < n; ++i) {
		hashmap_set(map, i, a[i]);
	}

	int before = errors;
	for (int i=0; i < n; ++i) {
		bool re = hashmap_has(map, i);
		if (re == false) {
			errors += 1;
		}
		++tests;
	}
	if (errors - before == 0) {
		pass("found all all keys");
	} else {
		char msg[200];
		sprintf(msg, "didn't find %d out of %d total keys", errors - before, n);
		fail(msg);
	}
	before = errors;
	
	int x = 10;
	int y[10] = {9922, 20000, 41234, 333, 123, 4499, 8999, 4321, 32864, 87777};
	for (int i=0; i < x; ++i){
		bool re = hashmap_has(map, y[i]);
		if (re) {
			errors += 1; 
		}
		++tests;
	}
	if (errors - before == 0) {
		pass("found no non-existent items");
	} else {
		char msg[200];
		sprintf(msg, "found %d out of %d items that didn't exist", errors - before, x);
		fail(msg);
	}

	int dMin = 7; 
	int dMax = 17; 

	for (int i = dMin; i <= dMax; ++i) {
		hashmap_delete(map, i);
	}

	before = errors;
	int i = 0;
	for (; i < dMin; ++i) {
		bool re = hashmap_has(map, i);
		if (!re) {
			errors += 1;
			int value = hashmap_get(map, i);
			red();
			printf("error: found deleted key: key %d value %d a[i] %d\n", i, value, a[i]);
			nocolor();
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
		bool re = hashmap_has(map, i);
		if (re) {
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
		bool re = hashmap_has(map, i);
		if (!re) {
			errors += 1;
			int value = hashmap_get(map, i);
			red();
			printf("error: found deleted key: key %d value %d a[i] %d\n", i, value, a[i]);
			nocolor();
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
		hashmap_set(map, i, a[i]);
	}

	before = errors;
	for (int i=0; i < n; ++i) {
		int re = hashmap_get(map, i);
		if (re != a[i]) {
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

	for (int i = 0; i < n; ++i) {
		hashmap_delete(map, i);
	}
	hashmap_free(map);
	
	summary(errors, tests);
	return errors > 0 ? 1 : 0;
}

