#include <stdio.h>
#include <stdlib.h>
#define True 1
#define False 0
#define MAX_SIZE 31

typedef int elem;

struct heap_tree{
	elem data[MAX_SIZE];
	int N;
};
typedef struct heap_tree HEAP;




//void TR_preorder(TREE_PTR v);
//void TR_inorder(TREE_PTR v);
//void TR_postorder(TREE_PTR v);
