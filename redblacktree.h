#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <stdlib.h>
#include <stdbool.h>

struct rbnode {
	int key;
	bool red;
	struct rbnode *p; 
	struct rbnode *r; 
	struct rbnode *l; 
};
typedef struct rbnode RBNode;

typedef struct {
	RBNode *root;
	RBNode *nil;
} RBTree;

RBTree *rbtree();
void rbtree_free(RBTree *tree);

void rbtree_insert(RBTree *tree, int value);
void rbtree_delete(RBTree *tree, int value);
bool rbtree_search(RBTree *tree, int value);

#endif
