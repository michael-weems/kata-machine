#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <stdlib.h>
#include <stdbool.h>

struct dll_node_t {
	int value;
	struct dll_node_t *next;
	struct dll_node_t *prev;
};

struct dll_t {
	struct dll_node_t *head;
	struct dll_node_t *tail;
};

struct dll_t *dll_create();
void dll_destroy(struct dll_t *list);

void dll_print(struct dll_t *list);
void dll_prepend(struct dll_t *list, int value);
void dll_append(struct dll_t *list, int value);
void dll_insert(struct dll_t *list, int idx, int value);
int dll_get(struct dll_t *list, int idx);
bool dll_contains(struct dll_t *list, int value);
int dll_length(struct dll_t *list);
int dll_remove(struct dll_t *list, int value);
int dll_remove_at(struct dll_t *list, int idx);

#endif
