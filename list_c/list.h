#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0


typedef int elem;

struct node{
	elem data;
	struct node *next;
};

typedef struct node LIST;
typedef struct node * LIST_PTR;
