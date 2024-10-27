#include "singlylinkedlist.h"

struct sll_node_t *sll_node_create(int value) {
	struct sll_node_t *node = malloc(sizeof(struct sll_node_t));
	node->next = NULL;
	node->value = value;
	return node;
}
void sll_node_destroy(struct sll_node_t *node) {
	if (node == NULL) {
		return;
	}

	struct sll_node_t *c = node;
	struct sll_node_t *n = node->next;
	while(n != NULL) {
		free(c);
		c = n;
		n = n->next;
	}
	free(c);
}

struct sll_t *sll_create(){
	struct sll_t *list = malloc(sizeof(struct sll_t));
	list->head = NULL;
	return list;
}
void sll_destroy(struct sll_t *list){
	sll_node_destroy(list->head);
	free(list);
}

void sll_insert(struct sll_t *list, int value){
	if (list->head == NULL) {
		list->head = sll_node_create(value);
		return;
	}

	struct sll_node_t *c = list->head;
	while (c->next != NULL) {
		c = c->next;
	}

	struct sll_node_t *node = sll_node_create(value);
	c->next = node;
}
int sll_get(struct sll_t *list, int idx){
	if (list->head == NULL) {
		return -1;
	}

	struct sll_node_t *c = list->head;
	for (int i = 0; i < idx; i++) {
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
bool sll_contains(struct sll_t *list, int value){
	struct sll_node_t *c = list->head;

	while (c != NULL) {
		if (c->value == value) {
			return true;
		}
		
		c = c->next;
	}
	return false;
}
int sll_length(struct sll_t *list){
	struct sll_node_t *c = list->head;

	int length = 0;
	while (c != NULL) {
		c = c->next;
		++length;
	}
	return length;

}
int sll_remove(struct sll_t *list, int value){
	if (list->head->value == value) {
		struct sll_node_t *node = list->head;
		list->head = list->head->next;
		int v = node->value;
		node->next = NULL;
		sll_node_destroy(node);
		return v;
	}

	struct sll_node_t *c = list->head;
	struct sll_node_t *n = list->head->next;
	while (n != NULL) {
		if (n->value == value) {
			int v = n->value;
			c->next = n->next;
			n->next = NULL;
			sll_node_destroy(n);
			return v;
		}
		c = c->next;
		n = c->next;
	}

	return -1;
}
int sll_remove_at(struct sll_t *list, int idx){
	if (idx == 0) {
		struct sll_node_t *node = list->head;
		list->head = list->head->next;
		int v = node->value;
		node->next = NULL;
		sll_node_destroy(node);
		return v;
	}

	struct sll_node_t *c = list->head;
	struct sll_node_t *n = list->head->next;
	for (int i = 0; i < idx-1; ++i) {
		if (n == NULL) {
			return -1;
		}
		c = c->next;
		n = c->next;
	}

	int v = n->value;
	c->next = n->next;
	n->next = NULL;
	sll_node_destroy(n);
	return v;
}

