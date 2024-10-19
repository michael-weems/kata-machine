#include <stdio.h>
#include "doublylinkedlist.h"

struct dll_node_t *dll_node_create(int value) {
	struct dll_node_t *node = malloc(sizeof(struct dll_node_t));
	node->value = value;
	node->prev = NULL;
	node->next = NULL;
	return node;
}
void dll_node_destroy(struct dll_node_t *node) {
	node->prev = NULL;
	node->next = NULL;
	free(node);
}

struct dll_t *dll_create(){
	struct dll_t *list = malloc(sizeof(struct dll_t));
	list->head = NULL;
	list->tail = NULL;
	return list;
}
void dll_destroy(struct dll_t *list){

	struct dll_node_t *c = list->head;
	while (c->next != NULL) {
		c = c->next;
		dll_node_destroy(c->prev);
	}
	dll_node_destroy(c);

	list->head = NULL;
	list->tail = NULL;
	free(list);
}
void dll_print(struct dll_t *list) {
	printf("[head] ");
	struct dll_node_t *c = list->head;
	while (c != NULL) {
		printf(" --> (%d)", c->value);
		c = c->next;
	}
	printf(" [tail]\n");
}

void dll_prepend(struct dll_t *list, int value){
	struct dll_node_t *node = dll_node_create(value);
	if (list->head == NULL) {
		list->head = node;
		list->tail = node;
		return;
	}

	node->next = list->head;
	list->head->prev = node;
	list->head = node;
}
void dll_append(struct dll_t *list, int value){
	struct dll_node_t *node = dll_node_create(value);
	if (list->tail == NULL) {
		list->head = node;
		list->tail = node;
		return;
	}

	node->prev = list->tail;
	list->tail->next = node;
	list->tail = node;
}
void dll_insert(struct dll_t *list, int idx, int value){
	struct dll_node_t *node = dll_node_create(value);
	if (list->head == NULL) {
		list->head = node;
		list->tail = node;
		return;
	}

	struct dll_node_t *c = list->head;
	int i = 0;
	for (; i < idx; ++i) {
		if (c->next == NULL) {
			c->next = node;
			node->prev = c;
			list->tail = node;
			return;
		}
		c = c->next;
	}

	node->next = c;
	node->prev = c->prev;

	if (c->prev == NULL) {
		list->head = node;
	} else {
		c->prev->next = node;
	}
	c->prev = node;
}
int dll_get(struct dll_t *list, int idx){
	if (list->head == NULL) {
		return -1;
	}

	struct dll_node_t *c = list->head;
	for (int i = 0; i < idx; ++i){
		if (c == NULL) {
			return -1;
		}
		c = c->next;
	}
	if (c == NULL) {
		return -1;
	}
	return c->value;
}
bool dll_contains(struct dll_t *list, int value){
	if (list->head == NULL) {
		return false;
	}

	struct dll_node_t *c = list->head;
	while (c != NULL) {
		if (c->value == value) {
			return true;
		}
		c = c->next;
	}
	return false;
}
int dll_length(struct dll_t *list){
	if (list->head == NULL) {
		return 0;
	}

	struct dll_node_t *c = list->head;
	int i = 0;
	while (c != NULL) {
		++i;
		c = c->next;
	}
	return i;
}
int dll_remove(struct dll_t *list, int value){
	if (list->head == NULL) {
		return -1;
	}

	struct dll_node_t *c = list->head;
	while (c != NULL) {
		if (c->value == value) {
			if (c->next != NULL) {
				c->next->prev = c->prev;
			}
			if (c->prev != NULL) {
				c->prev->next = c->next;
			}
			dll_node_destroy(c);
			return value;
		}
		c = c->next;
	}

	return -1;
}
int dll_remove_at(struct dll_t *list, int idx){
	if (list->head == NULL) {
		return -1;
	}

	if (list->head == list->tail) {
		struct dll_node_t *t = list->head;
		list->head = NULL;
		list->tail = NULL;

		int out = t->value;
		dll_node_destroy(t);
		return out;
	}

	int i = 0;
	struct dll_node_t *c = list->head;
	for (; i < idx; ++i) {
		if (c == NULL) {
			return -1;
		}
		c = c->next;
	}
	if (c == NULL) {
		return -1;
	}

	int out = c->value;

	if (c->next == NULL) {
		list->tail = c->prev;
	} else {
		c->next->prev = c->prev;
	}
	if (c->prev == NULL) {
		list->head = c->next;
	} else {
		c->prev->next = c->next;
	}
	dll_node_destroy(c);

	return out;
}
