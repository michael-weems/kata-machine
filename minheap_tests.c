#include <stdio.h>
#include "_testutils.h"
#include "minheap.h"

int main(int argc, char *argv[]) { 
	int tests = 0;
	int errors = 0;	

	struct MinHeap *heap = minheap_create(25);

	int n = 25;
	int a[25] = {5000, 10, 20, 90, 30, 40, 6000, 50, 25, 15, 5, 900, 45, 35, 100, 60, 75, 80, 55, 500, 85, 300, 250, 330, 3500};

	minheap_insert(heap, a[0]); // NOTE: insert 5000
	int e0[25] = {5000};
	errors += expect_array(e0, heap->arr, heap->size);
	tests += heap->size;

	minheap_insert(heap, a[1]); // NOTE: insert 10
	int e1[25] = {10, 5000};
	errors += expect_array(e1, heap->arr, heap->size);
	tests += heap->size;

	minheap_insert(heap, a[2]); // NOTE: insert 20
	int e2[25] = {10, 5000, 20};
	errors += expect_array(e2, heap->arr, heap->size);
	tests += heap->size;

	minheap_insert(heap, a[3]); // NOTE: insert 90
	int e3[25] = {10, 90, 20, 5000};
	errors += expect_array(e3, heap->arr, heap->size);
	tests += heap->size;

	minheap_insert(heap, a[4]); // NOTE: insert 30
	int e4[25] = {10, 30, 20, 5000, 90};
	errors += expect_array(e4, heap->arr, heap->size);
	tests += heap->size;

	minheap_insert(heap, a[5]); // NOTE: insert 40
	int e5[25] = {10, 30, 20, 5000, 90, 40};
	errors += expect_array(e5, heap->arr, heap->size);
	tests += heap->size;

	minheap_insert(heap, a[6]); // NOTE: insert 6000
	int e6[25] = {10, 30, 20, 5000, 90, 40, 6000};
	errors += expect_array(e6, heap->arr, heap->size);
	tests += heap->size;
	minheap_insert(heap, a[7]); // NOTE: insert 50
	int e7[25] = {10, 30, 20, 50, 90, 40, 6000, 5000};
	errors += expect_array(e7, heap->arr, heap->size);
	tests += heap->size;
	minheap_insert(heap, a[8]); // NOTE: insert 25 
	int e8[25] = {10, 25, 20, 30, 90, 40, 6000, 5000, 50};
	errors += expect_array(e8, heap->arr, heap->size);
	tests += heap->size;
	minheap_insert(heap, a[9]); // NOTE: insert 15
	int e9[25] = {10, 15, 20, 30, 25, 40, 6000, 5000, 50, 90};
	errors += expect_array(e9, heap->arr, heap->size);
	tests += heap->size;
	minheap_insert(heap, a[10]); // NOTE: insert 5
	int e10[25] = {5, 10, 20, 30, 15, 40, 6000, 5000, 50, 90, 25};
	errors += expect_array(e10, heap->arr, heap->size);
	tests += heap->size;
	minheap_insert(heap, a[11]); // NOTE: insert 900
	int e11[25] = {5, 10, 20, 30, 15, 40, 6000, 5000, 50, 90, 25, 900};
	errors += expect_array(e11, heap->arr, heap->size);
	tests += heap->size;
	minheap_insert(heap, a[12]); // NOTE: insert 45
	int e12[25] = {5, 10, 20, 30, 15, 40, 6000, 5000, 50, 90, 25, 900, 45};
	errors += expect_array(e12, heap->arr, heap->size);
	tests += heap->size;
	minheap_insert(heap, a[13]); // NOTE: insert 35
	int e13[25] = {5, 10, 20, 30, 15, 40, 35, 5000, 50, 90, 25, 900, 45, 6000};
	errors += expect_array(e13, heap->arr, heap->size);
	tests += heap->size;
	minheap_insert(heap, a[14]); // NOTE: insert 100
	int e14[25] = {5, 10, 20, 30, 15, 40, 35, 5000, 50, 90, 25, 900, 45, 6000, 100};
	errors += expect_array(e14, heap->arr, heap->size);
	tests += heap->size;
	minheap_insert(heap, a[15]); // NOTE: insert 60
	int e15[25] = {5, 10, 20, 30, 15, 40, 35, 60, 50, 90, 25, 900, 45, 6000, 100, 5000};
	errors += expect_array(e15, heap->arr, heap->size);
	tests += heap->size;
	minheap_insert(heap, a[16]); // NOTE: insert 75
	int e16[25] = {5, 10, 20, 30, 15, 40, 35, 60, 50, 90, 25, 900, 45, 6000, 100, 5000, 75};
	errors += expect_array(e16, heap->arr, heap->size);
	tests += heap->size;
	minheap_insert(heap, a[17]); // NOTE: insert 80
	int e17[25] = {5, 10, 20, 30, 15, 40, 35, 60, 50, 90, 25, 900, 45, 6000, 100, 5000, 75, 80};
	errors += expect_array(e17, heap->arr, heap->size);
	tests += heap->size;
	minheap_insert(heap, a[18]); // NOTE: insert 55
	int e18[25] = {5, 10, 20, 30, 15, 40, 35, 60, 50, 90, 25, 900, 45, 6000, 100, 5000, 75, 80, 55};
	errors += expect_array(e18, heap->arr, heap->size);
	tests += heap->size;
	minheap_insert(heap, a[19]); // NOTE: insert 500
	int e19[25] = {5, 10, 20, 30, 15, 40, 35, 60, 50, 90, 25, 900, 45, 6000, 100, 5000, 75, 80, 55, 500};
	errors += expect_array(e19, heap->arr, heap->size);
	tests += heap->size;
	minheap_insert(heap, a[20]); // NOTE: insert 85
	int e20[25] = {5, 10, 20, 30, 15, 40, 35, 60, 50, 85, 25, 900, 45, 6000, 100, 5000, 75, 80, 55, 500, 90};
	errors += expect_array(e20, heap->arr, heap->size);
	tests += heap->size;
	minheap_insert(heap, a[21]); // NOTE: insert 300
	int e21[25] = {5, 10, 20, 30, 15, 40, 35, 60, 50, 85, 25, 900, 45, 6000, 100, 5000, 75, 80, 55, 500, 90, 300};
	errors += expect_array(e21, heap->arr, heap->size);
	tests += heap->size;
	minheap_insert(heap, a[22]); // NOTE: insert 250
	int e22[25] = {5, 10, 20, 30, 15, 40, 35, 60, 50, 85, 25, 900, 45, 6000, 100, 5000, 75, 80, 55, 500, 90, 300, 250};
	errors += expect_array(e22, heap->arr, heap->size);
	tests += heap->size;
	minheap_insert(heap, a[23]); // NOTE: insert 330
	int e23[25] = {5, 10, 20, 30, 15, 40, 35, 60, 50, 85, 25, 330, 45, 6000, 100, 5000, 75, 80, 55, 500, 90, 300, 250, 900};
	errors += expect_array(e23, heap->arr, heap->size);
	tests += heap->size;
	minheap_insert(heap, a[24]); // NOTE: insert 3500
	int e24[25] = {5, 10, 20, 30, 15, 40, 35, 60, 50, 85, 25, 330, 45, 6000, 100, 5000, 75, 80, 55, 500, 90, 300, 250, 900, 3500};
	errors += expect_array(e24, heap->arr, heap->size);
	tests += heap->size;

	// NOTE: removals
	int o0 = minheap_remove(heap); 
	if (o0 == 5) {
		pass("remove 5");
	} else {
		errors += failInt(5, o0);
	}
	++tests;
	int er0[25] = {10, 15, 20, 30, 25, 40, 35, 60, 50, 85, 250, 330, 45, 6000, 100, 5000, 75, 80, 55, 500, 90, 300, 3500, 900};
	errors += expect_array(er0, heap->arr, heap->size);
	tests += heap->size;

	int o1 = minheap_remove(heap); 
	if (o1 == 10) {
		pass("remove 10");
	} else {
		errors += failInt(10, o1);
	}
	++tests;
	int er1[25] = {15, 25, 20, 30, 85, 40, 35, 60, 50, 90, 250, 330, 45, 6000, 100, 5000, 75, 80, 55, 500, 900, 300, 3500};
	errors += expect_array(er1, heap->arr, heap->size);
	tests += heap->size;

	int o2 = minheap_remove(heap); 
	if (o2 == 15) {
		pass("remove 15");
	} else {
		errors += failInt(15, o2);
	}
	++tests;
	int er2[25] = {20, 25, 35, 30, 85, 40, 100, 60, 50, 90, 250, 330, 45, 6000, 3500, 5000, 75, 80, 55, 500, 900, 300};
	errors += expect_array(er2, heap->arr, heap->size);
	tests += heap->size;

	int o3 = minheap_remove(heap); 
	if (o3 == 20) {
		pass("remove 20");
	} else {
		errors += failInt(20, o3);
	}
	++tests;
	int er3[25] = {25, 30, 35, 50, 85, 40, 100, 60, 55, 90, 250, 330, 45, 6000, 3500, 5000, 75, 80, 300, 500, 900};
	errors += expect_array(er3, heap->arr, heap->size);
	tests += heap->size;

	int o4 = minheap_remove(heap); 
	if (o4 == 25) {
		pass("remove 25");
	} else {
		errors += failInt(25, o4);
	}
	++tests;
	int er4[25] = {30, 50, 35, 55, 85, 40, 100, 60, 80, 90, 250, 330, 45, 6000, 3500, 5000, 75, 900, 300, 500};
	errors += expect_array(er4, heap->arr, heap->size);
	tests += heap->size;

	int o5 = minheap_remove(heap); 
	if (o5 == 30) {
		pass("remove 30");
	} else {
		errors += failInt(30, o5);
	}
	++tests;
	int er5[25] = {35, 50, 40, 55, 85, 45, 100, 60, 80, 90, 250, 330, 500, 6000, 3500, 5000, 75, 900, 300};
	errors += expect_array(er5, heap->arr, heap->size);
	tests += heap->size;

	int o6 = minheap_remove(heap); 
	if (o6 == 35) {
		pass("remove 35");
	} else {
		errors += failInt(35, o6);
	}
	++tests;
	int er6[25] = {40, 50, 45, 55, 85, 300, 100, 60, 80, 90, 250, 330, 500, 6000, 3500, 5000, 75, 900};
	errors += expect_array(er6, heap->arr, heap->size);
	tests += heap->size;

	int o7 = minheap_remove(heap); 
	if (o7 == 40) {
		pass("remove 40");
	} else {
		errors += failInt(40, o7);
	}
	++tests;
	int er7[25] = {45, 50, 100, 55, 85, 300, 900, 60, 80, 90, 250, 330, 500, 6000, 3500, 5000, 75};
	errors += expect_array(er7, heap->arr, heap->size);
	tests += heap->size;

	int o8 = minheap_remove(heap); 
	if (o8 == 45) {
		pass("remove 45");
	} else {
		errors += failInt(45, o8);
	}
	++tests;
	int er8[25] = {50, 55, 100, 60, 85, 300, 900, 75, 80, 90, 250, 330, 500, 6000, 3500, 5000};
	errors += expect_array(er8, heap->arr, heap->size);
	tests += heap->size;

	int o9 = minheap_remove(heap); 
	if (o9 == 50) {
		pass("remove 50");
	} else {
		errors += failInt(50, o9);
	}
	++tests;
	int er9[25] = {55, 60, 100, 75, 85, 300, 900, 5000, 80, 90, 250, 330, 500, 6000, 3500};
	errors += expect_array(er9, heap->arr, heap->size);
	tests += heap->size;

	int o10 = minheap_remove(heap); 
	if (o10 == 55) {
		pass("remove 55");
	} else {
		errors += failInt(55, o10);
	}
	++tests;
	int er10[25] = {60, 75, 100, 80, 85, 300, 900, 5000, 3500, 90, 250, 330, 500, 6000};
	errors += expect_array(er10, heap->arr, heap->size);
	tests += heap->size;

	int o11 = minheap_remove(heap); 
	if (o11 == 60) {
		pass("remove 60");
	} else {
		errors += failInt(60, o11);
	}
	++tests;
	int er11[25] = {75, 80, 100, 3500, 85, 300, 900, 5000, 6000, 90, 250, 330, 500};
	errors += expect_array(er11, heap->arr, heap->size);
	tests += heap->size;

	int o12 = minheap_remove(heap); 
	if (o12 == 75) {
		pass("remove 75");
	} else {
		errors += failInt(75, o12);
	}
	++tests;
	int er12[25] = {80, 85, 100, 3500, 90, 300, 900, 5000, 6000, 500, 250, 330};
	errors += expect_array(er12, heap->arr, heap->size);
	tests += heap->size;

	int o13 = minheap_remove(heap); 
	if (o13 == 80) {
		pass("remove 80");
	} else {
		errors += failInt(80, o13);
	}
	++tests;
	int er13[25] = {85, 90, 100, 3500, 250, 300, 900, 5000, 6000, 500, 330};
	errors += expect_array(er13, heap->arr, heap->size);
	tests += heap->size;

	int o14 = minheap_remove(heap); 
	if (o14 == 85) {
		pass("remove 85");
	} else {
		errors += failInt(85, o14);
	}
	++tests;
	int er14[25] = {90, 250, 100, 3500, 330, 300, 900, 5000, 6000, 500};
	errors += expect_array(er14, heap->arr, heap->size);
	tests += heap->size;

	int o15 = minheap_remove(heap); 
	if (o15 == 90) {
		pass("remove 90");
	} else {
		errors += failInt(90, o15);
	}
	++tests;
	int er15[25] = {100, 250, 300, 3500, 330, 500, 900, 5000, 6000};
	errors += expect_array(er15, heap->arr, heap->size);
	tests += heap->size;

	int o16 = minheap_remove(heap); 
	if (o16 == 100) {
		pass("remove 100");
	} else {
		errors += failInt(100, o16);
	}
	++tests;
	int er16[25] = {250, 330, 300, 3500, 6000, 500, 900, 5000};
	errors += expect_array(er16, heap->arr, heap->size);
	tests += heap->size;

	int o17 = minheap_remove(heap); 
	if (o17 == 250) {
		pass("remove 250");
	} else {
		errors += failInt(250, o17);
	}
	++tests;
	int er17[25] = {300, 330, 500, 3500, 6000, 5000, 900};
	errors += expect_array(er17, heap->arr, heap->size);
	tests += heap->size;

	int o18 = minheap_remove(heap); 
	if (o18 == 300) {
		pass("remove 300");
	} else {
		errors += failInt(300, o18);
	}
	++tests;
	int er18[25] = {330, 900, 500, 3500, 6000, 5000};
	errors += expect_array(er18, heap->arr, heap->size);
	tests += heap->size;

	int o19 = minheap_remove(heap); 
	if (o19 == 330) {
		pass("remove 330");
	} else {
		errors += failInt(330, o19);
	}
	++tests;
	int er19[25] = {500, 900, 5000, 3500, 6000};
	errors += expect_array(er19, heap->arr, heap->size);
	tests += heap->size;

	int o20 = minheap_remove(heap); 
	if (o20 == 500) {
		pass("remove 500");
	} else {
		errors += failInt(500, o20);
	}
	++tests;
	int er20[25] = {900, 3500, 5000, 6000};
	errors += expect_array(er20, heap->arr, heap->size);
	tests += heap->size;

	int o21 = minheap_remove(heap); 
	if (o21 == 900) {
		pass("remove 900");
	} else {
		errors += failInt(900, o21);
	}
	++tests;
	int er21[25] = {3500, 6000, 5000};
	errors += expect_array(er21, heap->arr, heap->size);
	tests += heap->size;

	int o22 = minheap_remove(heap); 
	if (o22 == 3500) {
		pass("remove 3500");
	} else {
		errors += failInt(3500, o22);
	}
	++tests;
	int er22[25] = {5000, 6000};
	errors += expect_array(er22, heap->arr, heap->size);
	tests += heap->size;

	int o23 = minheap_remove(heap); 
	if (o23 == 5000) {
		pass("remove 5000");
	} else {
		errors += failInt(5000, o23);
	}
	++tests;
	int er23[25] = {6000};
	errors += expect_array(er23, heap->arr, heap->size);
	tests += heap->size;

	int o24 = minheap_remove(heap); 
	if (o24 == 6000) {
		pass("remove 6000");
	} else {
		errors += failInt(6000, o24);
	}
	++tests;
	int er24[25] = {};
	errors += expect_array(er24, heap->arr, heap->size);
	tests += heap->size;

	minheap_destroy(heap);
	
	summary(errors, tests);
	return errors > 0 ? 1 : 0;

}

