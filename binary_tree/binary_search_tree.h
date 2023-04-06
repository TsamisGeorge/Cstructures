#include <stdio.h>
#include <stdlib.h>
#define True 1
#define False 0

typedef int elem;

struct node{
	elem data;
	struct node *left;
	struct node *right;
};

typedef struct node TREE_NODE;
typedef struct node *TREE_PTR;

//init the tree
void TR_init(TREE_PTR *root);
//see if tree is empty
int TR_empty(TREE_PTR root);
//get value of node
elem TR_data(TREE_PTR p);

//insertions if root or node == NULL
int TR_insert_root(TREE_PTR *root, elem x);
int TR_insert_left(TREE_PTR node, elem x);
int TR_insert_right(TREE_PTR node, elem x);
//deletions if child of root or node == NULL
int TR_del_root(TREE_PTR *root, elem *x);
int TR_del_left_child(TREE_PTR parent, elem *x);
int TR_del_right_child(TREE_PTR parent, elem *x);
//print the value of the node
void TR_print_node(TREE_PTR node);
//preorder, inorder, and postorder traversal methods
void TR_preorder(TREE_PTR v);
void TR_inorder(TREE_PTR v);
void TR_postorder(TREE_PTR v);
int TR_search_BST(TREE_PTR root, elem x);
