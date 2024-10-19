#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <stdlib.h>
#include <stdbool.h>

struct sll_node_t {
	int value;
	struct sll_node_t *next;
};

struct sll_t {
	struct sll_node_t *head;
};

struct sll_t *sll_create();
void sll_destroy(struct sll_t *list);

void sll_insert(struct sll_t *list, int value);
int sll_get(struct sll_t *list, int idx);
bool sll_contains(struct sll_t *list, int value);
int sll_length(struct sll_t *list);
int sll_remove(struct sll_t *list, int value);
int sll_remove_at(struct sll_t *list, int idx);

#endif
