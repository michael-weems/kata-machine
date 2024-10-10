#include <stdio.h>
#include <stdbool.h>
#include "_testutils.h"
#include "arraylist.h"

int main(int argc, char *argv[]) { 

	int tests = 0;
	int errors = 0;	

	Arraylist *list = arraylist(3);

	arraylist_append(list, 5);
	arraylist_append(list, 7);
	arraylist_append(list, 9);

	int a_re = arraylist_get(list, 2);
	int a_ex = 9;
	if (a_ex == a_re) {
		pass("idx 2 == 9");
	} else {
		errors += failInt(a_ex, a_re);
	}
	++tests;

	int b_re = arraylist_remove_at(list, 1);
	int b_ex = 7;
	if (b_ex == b_re) {
		pass("removeAt 1 == 7");
	} else {
		errors += failInt(b_ex, b_re);
	}
	++tests;

	int c_re = list->length;
	int c_ex = 2;
	if (c_ex == c_re) {
		pass("length == 2");
	} else {
		errors += failInt(c_ex, c_re);
	}
	++tests;

	arraylist_append(list, 11);

	int d_re = arraylist_remove_at(list, 1);
	int d_ex = 9;
	if (d_ex == d_re) {
		pass("remove_at 1 == 9");
	} else {
		errors += failInt(d_ex, d_re);
	}
	++tests;

	int e_re = arraylist_remove(list, 9);
	int e_ex = -1;
	if (e_ex == e_re) {
		pass("remove 9 -> -1");
	} else {
		errors += failInt(e_ex, e_re);
	}
	++tests;

	int f_re = arraylist_remove_at(list, 0);
	int f_ex = 5;
	if (f_ex == f_re) {
		pass("remove_at 0 -> 5");
	} else {
		errors += failInt(f_ex, f_re);
	}
	++tests;

	int g_re = arraylist_remove_at(list, 0);
	int g_ex = 11;
	if (g_ex == g_re) {
		pass("remove_at 0 -> 11");
	} else {
		errors += failInt(g_ex, g_re);
	}
	++tests;

	int h_re = list->length;
	int h_ex = 0;
	if (h_ex == h_re) {
		pass("length == 0");
	} else {
		errors += failInt(h_ex, h_re);
	}
	++tests;

	arraylist_prepend(list, 5);
	arraylist_prepend(list, 7);
	arraylist_prepend(list, 9);

	int i_re = arraylist_get(list, 2);
	int i_ex = 5;
	if (i_ex == i_re) {
		pass("get 2 -> 5");
	} else {
		errors += failInt(i_ex, i_re);
	}
	++tests;

	int j_re = arraylist_get(list, 0);
	int j_ex = 9;
	if (j_ex == j_re) {
		pass("get 0 -> 9");
	} else {
		errors += failInt(j_ex, j_re);
	}
	++tests;

	int k_re = arraylist_remove(list, 9);
	int k_ex = 9;
	if (k_ex == k_re) {
		pass("remove 9 -> 9");
	} else {
		errors += failInt(k_ex, k_re);
	}
	++tests;

	int l_re = list->length;
	int l_ex = 2;
	if (l_ex == l_re) {
		pass("length == 2");
	} else {
		errors += failInt(l_ex, l_re);
	}
	++tests;

	int m_re = arraylist_get(list, 0);
	int m_ex = 7;
	if (m_ex == m_re) {
		pass("get 0 -> 7");
	} else {
		errors += failInt(m_ex, m_re);
	}
	++tests;

	arraylist_free(list);
	
	summary(errors, tests);
	return errors > 0 ? 1 : 0;
}

