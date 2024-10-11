#include <stdio.h>
#include "redblacktree.h"

void rb_delete(RBTree *t, RBNode *curr);
void rb_delete_fixup(RBTree *t, RBNode *curr);
void rb_transplant(RBTree *t, RBNode *u, RBNode *v);
void rb_insert(RBTree *t, RBNode *node);
void rb_insert_fixup(RBTree *t, RBNode *curr);
void rb_left_rotate(RBTree *t, RBNode *node);
void rb_right_rotate(RBTree *t, RBNode *node);
RBNode *rb_tree_minimum(RBTree *t, RBNode *node);
RBNode *rb_tree_maximum(RBTree *t, RBNode *node);
RBNode *rb_find(RBTree *t, RBNode *node, int key);

RBNode *rbnode(int key);
RBNode *rbnode(int key) {
	RBNode *node = (RBNode *)malloc(sizeof(RBNode));
	node->red = false;
	node->p = NULL;
	node->r = NULL;
	node->l = NULL;
	node->key = key;

	return node;
}
void rbnode_free(RBNode *node); 
void rbnode_free(RBNode *node) {
	if (node == NULL) {
		return;
	}

	node->p = NULL;
	node->r = NULL;
	node->l = NULL;
	free(node);
}

RBTree *rbtree() {
	RBTree *tree = (RBTree *)malloc(sizeof(RBTree *));
	tree->nil = rbnode(-1);
	tree->root = tree->nil;
	return tree;
}
void rbtree_free(RBTree *tree) {
	if (tree->root == NULL) {
		return;
	}

	// TODO: walk the tree, freeing each node post-order
}

void printNode(int depth, RBNode *n) {
	for (int i = 0; i < depth; ++i) {
		printf("    ");
	}
	printf("%s (%d)\n",  n->red ? "R" : "B", n->key);
}
void printRBTree(RBTree *t, RBNode *n, int depth, int order) {
	if (n == t->nil) {
		for (int i = 0; i < depth; ++i) {
			printf("    ");
		}
		printf("%s (nil)\n",  n->red ? "R" : "B");
		return;
	}

	if (order == -1) {
		printNode(depth, n);
	}
	printRBTree(t, n->l, depth + 1, order);
	if (order == 0) {
		printNode(depth, n);
	}
	printRBTree(t, n->r, depth + 1, order);
	if (order == 1) {
		printNode(depth, n);
	}
}

// NOTE: external interface functions
bool rbtree_search(RBTree *tree, int key) {
	return false;
}
void rbtree_insert(RBTree *tree, int key) {
	
}
void rbtree_delete(RBTree *t, int key) {
}

// NOTE: internal implementation functions
RBNode *rb_find(RBTree *t, RBNode *node, int key) {

}
void rb_delete(RBTree *t, RBNode *z) {
	
}
void rb_delete_fixup(RBTree *t, RBNode *curr) {
	
}
void rb_insert(RBTree *t, RBNode *z) {
	
}
void rb_insert_fixup(RBTree *t, RBNode *z) {
	
}
void rb_transplant(RBTree *t, RBNode *u, RBNode *v) {
	
}
void rb_left_rotate(RBTree *t, RBNode *x) {
	
}
void rb_right_rotate(RBTree *t, RBNode *x) {
	
}
RBNode *rb_tree_minimum(RBTree *t, RBNode *x) {
	
}
RBNode *rb_tree_maximum(RBTree *t, RBNode *x) {
	
}
