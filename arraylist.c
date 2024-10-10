#include "arraylist.h"

void arraylist_grow(Arraylist *list);
void arraylist_grow(Arraylist *list) {
	list->capacity *= 2;
	list->arr = (int *)realloc(list->arr, list->capacity);
	// TODO: perror w/ errno?
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
	
}

void arraylist_append(Arraylist *list, int value) {
	
}

void arraylist_insert(Arraylist *list, int value, int idx) {
	
}

int arraylist_remove(Arraylist *list, int value) {

}

int arraylist_remove_at(Arraylist *list, int idx) {
	
}

int arraylist_get(Arraylist *list, int idx) {
	
}
