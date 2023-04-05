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



