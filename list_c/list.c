#include "list.h"

//passing the head pointer as a reference, when calling LL_init we will use LL_init(&head) which means we put the address of a pointer in it,
//basically a pointer to a pointer, and then using *head = NULL;, lets take an outside pointer called head, and the pointer that has as value the address of head is h, 
void LL_init(LIST_PTR *h)
{
	*head = NULL;
}

int LL_empty(LIST_PTR h)
{
	return head == NULL;
}
