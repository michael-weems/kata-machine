#include "arraylist.h"

void arraylist_grow(Arraylist *list);
void arraylist_grow(Arraylist *list) {
	list->capacity *= 2;
	list->arr = (int *)realloc(list->arr, list->capacity);
	// TODO: perror w/ errno?
}

void arraylist_shift_right(Arraylist *list, int idx);
void arraylist_shift_right(Arraylist *list, int idx) {
	for (int i = list->length-1; i > idx; --i) {
		list->arr[i] = list->arr[i-1];
	}
}

void arraylist_shift_left(Arraylist *list, int idx);
void arraylist_shift_left(Arraylist *list, int idx) {
	for (int i = idx; i < list->length-1; ++i) {
		list->arr[i] = list->arr[i+1];
	}
}

Arraylist *arraylist(int capacity) {
	Arraylist *list = malloc(sizeof(Arraylist));
	list->capacity = capacity;
	list->length = 0;

	int *arr = (int *)calloc(sizeof(int *), capacity);
	// TODO: perror w/ errno?
	list->arr = arr;

	return list;
}

void arraylist_free(Arraylist *list) {
	free(list->arr);
	free(list);
}

void arraylist_prepend(Arraylist *list, int value) {
	++list->length;
	if (list->length == 1) {
		list->arr[0] = value;
		return;
	}
	if (list->length > list->capacity) {
		arraylist_grow(list);
		// TODO: error handling?
	}
	arraylist_shift_right(list, 0);

	list->arr[0] = value;
}

void arraylist_append(Arraylist *list, int value) {
	++list->length;
	if (list->length == 1) {
		list->arr[0] = value;	
		return;
	}

	if (list->length > list->capacity) {
		arraylist_grow(list);
		// TODO: error handling?
	}

	list->arr[list->length-1] = value;
}

void arraylist_insert(Arraylist *list, int value, int idx) {
	if (idx < 0 || idx > list->length) {
		return;
	}
	++list->length;

	if (list->length > list->capacity) {
		arraylist_grow(list);
		// TODO: error handling?
	}

	arraylist_shift_right(list, idx);
	list->arr[idx] = value;
}

int arraylist_remove(Arraylist *list, int value) {

	int idx = -1;
	for (int i = 0; i < list->length; ++i) {
		if (list->arr[i] == value) {
			idx = i;
			break;
		}
	}

	if (idx == -1) {
		return -1;
	}

	arraylist_shift_left(list, idx);

	--list->length;
	return value;
}

int arraylist_remove_at(Arraylist *list, int idx) {
	if (idx < 0 || idx > list->length) {
		return -1;
	}

	int value = list->arr[idx];
	arraylist_shift_left(list, idx);
	--list->length;
	return value;
}

int arraylist_get(Arraylist *list, int idx) {
	if (idx < 0 || idx > list->length) {
		return -1;
	}

	return list->arr[idx];
}
