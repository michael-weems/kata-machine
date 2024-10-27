#ifndef BST_H
#define BST_H

#include <stdlib.h>
#include <stdbool.h>

struct btnode {
	int key;
	struct btnode *r; 
	struct btnode *l; 
};

struct btnode *btnode_create(int key);
void btnode_free(struct btnode *root);

void bst_insert(struct btnode *root, int value);
void bst_delete(struct btnode *root, int value);
bool bst_search(struct btnode *root, int value);

#endif
