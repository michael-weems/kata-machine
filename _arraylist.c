#include "_arraylist.h"

void al_grow(Arrlist *list);
void al_grow(Arrlist *list) {
	list->capacity *= 2;
	list->arr = (int *)realloc(list->arr, list->capacity);
	// TODO: perror w/ errno?
}

void al_shift_right(Arrlist *list, int idx);
void al_shift_right(Arrlist *list, int idx) {
	for (int i = list->length-1; i > idx; --i) {
		list->arr[i] = list->arr[i-1];
	}
}

void al_shift_left(Arrlist *list, int idx);
void al_shift_left(Arrlist *list, int idx) {
	for (int i = idx; i < list->length-1; ++i) {
		list->arr[i] = list->arr[i+1];
	}
}

Arrlist *al_create(int capacity) {
	Arrlist *list = malloc(sizeof(Arrlist));
	list->capacity = capacity;
	list->length = 0;

	int *arr = (int *)calloc(sizeof(int *), capacity);
	// TODO: perror w/ errno?
	list->arr = arr;

	return list;
}

void al_free(Arrlist *list) {
	free(list->arr);
	free(list);
}

void al_prepend(Arrlist *list, int value) {
	++list->length;
	if (list->length == 1) {
		list->arr[0] = value;
		return;
	}
	if (list->length > list->capacity) {
		al_grow(list);
		// TODO: error handling?
	}
	al_shift_right(list, 0);

	list->arr[0] = value;
}

void al_append(Arrlist *list, int value) {
	++list->length;
	if (list->length == 1) {
		list->arr[0] = value;	
		return;
	}

	if (list->length > list->capacity) {
		al_grow(list);
		// TODO: error handling?
	}

	list->arr[list->length-1] = value;
}

void al_insert(Arrlist *list, int value, int idx) {
	if (idx < 0 || idx > list->length) {
		return;
	}
	++list->length;

	if (list->length > list->capacity) {
		al_grow(list);
		// TODO: error handling?
	}

	al_shift_right(list, idx);
	list->arr[idx] = value;
}

int al_remove(Arrlist *list, int value) {

	int idx = al_index_of(list, value);
	if (idx == -1) {
		return -1;
	}

	al_shift_left(list, idx);

	--list->length;
	return value;
}

int al_remove_at(Arrlist *list, int idx) {
	if (idx < 0 || idx > list->length) {
		return -1;
	}

	int value = list->arr[idx];
	al_shift_left(list, idx);
	--list->length;
	return value;
}

int al_get(Arrlist *list, int idx) {
	if (idx < 0 || idx > list->length) {
		return -1;
	}

	return list->arr[idx];
}
int al_index_of(Arrlist *list, int value){
	int idx = -1;
	for (int i = 0; i < list->length; ++i) {
		if (list->arr[i] == value) {
			idx = i;
			break;
		}
	}
	return idx;
}
void al_update(Arrlist *list, int idx, int value) {
	if (idx < 0 || idx > list->length) {
		return;
	}
	list->arr[idx] = value;
}
