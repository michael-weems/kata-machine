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

RBTree *rbtree_create() {
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

void util_rbnode_print(RBNode *n, int depth) {
	for (int i = 0; i < depth; ++i) {
		printf("    ");
	}
	printf("%s (%d)\n",  n->red ? "R" : "B", n->key);
}
void util_rb_print(RBTree *t, RBNode *n, int depth, int order) {
	if (n == t->nil) {
		for (int i = 0; i < depth; ++i) {
			printf("    ");
		}
		printf("%s (nil)\n",  n->red ? "R" : "B");
		return;
	}

	if (order == -1) {
		util_rbnode_print(n, depth);
	}
	util_rb_print(t, n->l, depth + 1, order);
	if (order == 0) {
		util_rbnode_print(n, depth);
	}
	util_rb_print(t, n->r, depth + 1, order);
	if (order == 1) {
		util_rbnode_print(n, depth);
	}
}

// NOTE: external interface functions
bool rbtree_search(RBTree *tree, int key) {
	RBNode *node = rb_find(tree, tree->root, key);
	return node != NULL;
}

void rbtree_insert(RBTree *tree, int key) {
	RBNode *node = rbnode(key);
	rb_insert(tree, node);
}
void rbtree_delete(RBTree *t, int key) {
	if (t->root == t->nil) {
		return;
	}
	RBNode *node = rb_find(t, t->root, key);
	if (node == NULL) return;

	rb_delete(t, node);
}

// NOTE: internal implementation functions
void rb_delete(RBTree *t, RBNode *z) {
	RBNode *y = z;
	bool y_og_color = y->red;
	
	RBNode *x;
	if (z->l == t->nil) {
		x = z->r;
		rb_transplant(t, z, z->r);
	} else if(z->r == t->nil) {
		x = z->l;
		rb_transplant(t, z, z->l);
	} else {
		y = rb_tree_minimum(t, z->r);
		y_og_color = y->red;
		x = y->r;

		if (y != z->r){
			rb_transplant(t, y, y->r);
			y->r = z->r;
			y->r->p = y;
		} else {
			x->p = y;
		}

		rb_transplant(t, z, y);
		y->l = z->l;
		y->l->p = y;
		y->red = z->red;
	}
	if (y_og_color == false) {
		rb_delete_fixup(t, x);
	}
}
void rb_delete_fixup(RBTree *t, RBNode *curr) {
	while (curr != t->root && curr->red == false) {
		if (curr == curr->p->l) {
			// NOTE: curr is a left child
			RBNode *sibling = curr->p->r;
			if (sibling->red) {
				// NOTE: case 1
				sibling->red = false;
				curr->p->red = true;
				rb_left_rotate(t, curr->p);
				sibling = curr->p->r;
			}
			if (sibling->l->red == false && sibling->r->red == false) {
				// NOTE: case 2
				sibling->red = true;
				curr = curr->p;
			} else {
				if (sibling->r->red == false) {
					// NOTE: case 3
					sibling->l->red = false;
					sibling->red = true;
					rb_right_rotate(t, sibling);
					sibling = curr->p->r;
				}
				// NOTE: case 4
				sibling->red = curr->p->red;
				curr->p->red = false;
				sibling->r->red = false;
				rb_left_rotate(t, curr->p);
				curr = t->root;
			}
		} else {
			// NOTE: curr is a right child
			RBNode *sibling = curr->p->l;
			if (sibling->red) {
				// NOTE: case 1
				sibling->red = false;
				curr->p->red = true;
				rb_right_rotate(t, curr->p);
				sibling = curr->p->l;
			}
			if (sibling->r->red == false && sibling->l->red == false) {
				// NOTE: case 2
				sibling->red = true;
				curr = curr->p;
			} else {
				if (sibling->l->red == false) {
					// NOTE: case 3
					sibling->r->red = false;
					sibling->red = true;
					rb_left_rotate(t, sibling);
					sibling = curr->p->l;
				}
				// NOTE: case 4
				sibling->red = curr->p->red;
				curr->p->red = false;
				sibling->l->red = false;
				rb_right_rotate(t, curr->p);
				curr = t->root;
			}
		}
	}
	curr->red = false;
}



void rb_insert(RBTree *t, RBNode *z) {
	RBNode *x = t->root;   // node being compared with z
	RBNode *y = t->nil;     // y will be parent of z
	while (x != t->nil) {         // descend ntil reaching the sentinel
		y = x;
		if (z->key < x->key) {
			x = x->l;
		} else {
			x = x->r;
		}
	}
	z->p = y; // found the location - insert z with parent y
	
	if (y == t->nil) {
		t->root = z;  // tree was empty
	} else if (z->key < y->key) {
		y->l = z;
	} else {
		y->r = z;
	}

	z->l = t->nil;
	z->r = t->nil;
	z->red = true; // new node starts as red
	rb_insert_fixup(t, z); // correct any violations of red-black properties
}
void rb_insert_fixup(RBTree *t, RBNode *z) {
	if (z == t->root) {
		t->root->red = false;
		return;
	}

	while (z->p->red){
		if (z->p->p->l != t->nil && z->p == z->p->p->l) { 
			// z's parent is a left child
			RBNode *y = z->p->p->r; // y is z's uncle
			if (y->red) { // are z's parent and uncle both red?
				// NOTE: case 1
				z->p->red = false;
				y->red = false;
				z->p->p->red = true;
				z = z->p->p;
			} else {
				if (z == z->p->r) {
					// NOTE: case 2
					z = z->p;
					rb_left_rotate(t, z);
				}
				// NOTE: case 3
				z->p->red = false;
				z->p->p->red = true;
				rb_right_rotate(t, z->p->p);
			}
		} else {
			// z's parent is a right child
			RBNode *y = z->p->p->l; // y is z's uncle
			if (y->red) { // are z's parent and uncle both red?
				// NOTE: case 1
				z->p->red = false;
				y->red = false;
				z->p->p->red = true;
				z = z->p->p;
			} else {
				if (z == z->p->l) {
					// NOTE: case 2
					z = z->p;
					rb_right_rotate(t, z);
				}
				// NOTE: case 3
				z->p->red = false;
				z->p->p->red = true;
				rb_left_rotate(t, z->p->p);
			}
		}
	}
	t->root->red = false;
}

void rb_transplant(RBTree *t, RBNode *u, RBNode *v) {
	if (u->p == t->nil) {
		t->root = v;
	} else if (u == u->p->l) {
		u->p->l = v;
	} else {
		u->p->r = v;
	}
	v->p = u->p;
}

void rb_left_rotate(RBTree *t, RBNode *x) {
	RBNode *y = x->r;
	x->r = y->l;       // turn y's left subtree into x's right subtree
	if (y->l != t->nil) {   // if y's left subtree is not empty...
		y->l->p = x;  // ... then x becomes the parent of the subtree's root
	}
	y->p = x->p;          // x's parent becomes y's parent
	if (x->p == t->nil) {   // if x was the root...
		t->root = y;   // ...then y becomes the root
	} else if (x == x->p->l) { // otherwise, if x was a left child
		x->p->l = y;       // ... then y becomes a left child
	} else {  
		x->p->r = y;       // otherwise, x was a right child, and now y is
	}
	y->l = x;
	x->p = y;
}
void rb_right_rotate(RBTree *t, RBNode *x) {
	RBNode *y = x->l;
	x->l = y->r;       // turn y's right subtree into x's left subtree
	if (y->r != t->nil) {   // if y's right subtree is not empty...
		y->r->p = x;  // ... then x becomes the parent of the subtree's root
	}
	y->p = x->p;          // x's parent becomes y's parent
	if (x->p == t->nil) {   // if x was the root...
		t->root = y;   // ...then y becomes the root
	} else if (x == x->p->r) { // otherwise, if x was a right child
		x->p->r = y;       // ... then y becomes a right child
	} else {  
		x->p->l = y;       // otherwise, x was a left child, and now y is
	}
	y->r = x;
	x->p = y;
}
RBNode *rb_tree_minimum(RBTree *t, RBNode *x) {
	while (x->l != t->nil) x = x->l;
	return x;
}
RBNode *rb_tree_maximum(RBTree *t, RBNode *x) {
	while (x->r != t->nil) x = x->r;
	return x;
}

RBNode *rb_find(RBTree *t, RBNode *node, int key) {
	if (node == t->nil) {
		return NULL;
	}

	if (node->key == key) {
		return node;
	}

	RBNode *found = NULL;

	if (node->key < key) {
		return rb_find(t, node->r, key);
	} else {
		return rb_find(t, node->l, key);
	}
}
