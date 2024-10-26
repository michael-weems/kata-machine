#include <stdio.h>
#include <stdbool.h>
#include "_testutils.h"
#include "bst.h"

int main(int argc, char *argv[]) { 

	int tests = 0;
	int errors = 0;	

	int n = 25;
	int a[25] = {5000, 10, 20, 90, 30, 40, 6000, 50, 25, 15, 5, 900, 45, 35, 100, 60, 75, 80, 55, 500, 85, 300, 250, 330, 3500};

	struct btnode *root = btnode_create(a[0]);
	for (int i = 1; i < n; ++i) {
		bst_insert(root, a[i]);
	}

	int before = errors;
	for (int i=0; i < n; ++i) {
		bool re = bst_search(root, a[i]);
		if (re == false) {
			errors += 1;
		}
		++tests;
	}
	if (errors - before == 0) {
		pass("found all items added to tree");
	} else {
		char msg[200];
		sprintf(msg, "didn't find %d out of %d total items", errors - before, n);
		fail(msg);
	}

	before = errors;
	int x = 10;
	int y[10] = {9, 2, 4, 333, 123, 4499, 8999, 4321, 34};
	for (int i=0; i < x; ++i){
		bool re = bst_search(root, y[i]);
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
		bst_delete(root, a[i]);
	}

	before = errors;
	int i = 0;
	for (; i < dMin; ++i) {
		bool re = bst_search(root, a[i]);
		if (!re) {
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
		bool re = bst_search(root, a[i]);
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
		bool re = bst_search(root, a[i]);
		if (!re) {
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
		bst_insert(root, a[i]);
	}

	before = errors;
	for (int i=0; i < n; ++i) {
		bool re = bst_search(root, a[i]);
		if (!re) {
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
		bst_delete(root, a[i]);
	}
	btnode_free(root);
	
	summary(errors, tests);
	return errors > 0 ? 1 : 0;
}

