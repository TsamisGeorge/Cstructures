#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

//synonym for the name of int
typedef int elem;

//struct of type node
struct node{
	//has elem data and a pointer to a struct node
	elem data;
	struct node *next;
};

//synonyms for the names of node and  also node pointer
typedef struct node LIST_NODE;
typedef struct node * LIST_PTR;

void LL_init(LIST_PTR *head);
int LL_empty(LIST_PTR head);
int LL_data(LIST_PTR p);
int LL_insert_start(LIST_PTR *head, elem x);
