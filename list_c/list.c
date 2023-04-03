#include "list.h"

//passing the head pointer as a reference, when calling LL_init we will use LL_init(&head) which means we put the address of a pointer in it,
//basically a pointer to a pointer, and then using *head = NULL;, lets take an outside pointer called head, and the pointer that has as value the address of head is h, 
void LL_init(LIST_PTR *head)
{
	*head = NULL;
}

int LL_empty(LIST_PTR head)
{
	return head == NULL;
}

int LL_data(LIST_PTR p)
{
	return p -> data;
}

int LL_insert_start(LIST_PTR *head, elem x)
{
	LIST_PTR new_node;
	new_node = malloc(sizeof(LIST_NODE));
	if(!new_node)
	{
		printf("\nUnable to allocate memory.");
		return FALSE;
	}
	new_node -> data = x;
	new_node->next= *head
	*head = new_node;
	return TRUE;
}

int LL_insert_after(LIST_PTR p, elem x)
{
	LIST_PTR new_node;
	new_node = malloc(sizeof(LIST_NODE));
	if(!new_node)
	{
		printf("Unable to allocate memory");
		return FALSE;
	}
	new_node -> data = x;
	new_node -> next = p -> next;
	p -> next = new_node;	
	return TRUE;
}

int LL_delete_start(LIST_PTR *head, elem *x)
{
	LIST_PTR current;
	if(*head == NULL)
		return FALSE;
	current = *head;
	*x = current -> data;
	(*head) = (*head) -> next;
	free(current);
	return TRUE;
}

int LL_delete_after(LIST_PTR prev, *x)
{
	LIST_PTR current;
	if(prev -> next == NULL)
		return FALSE;
	current = prev -> next;
	*x = current -> data
	prev -> next = current -> next;
	free(current);
	return TRUE;
}
//!!!!!!
void LL_destroy(LIST_PTR * head)
{
	LIST_PTR ptr;
	while(*head != NULL)
	{
		ptr = *head;
		*head = (*head) -> next;
		free(ptr);
	}
}

void LL_print(LIST_PTR head)
{
	LIST_PTR current;
	current = head;
	while(current!= NULL)
	{
		printf("%d", current ->data);
		current = current -> next;
	}
}
