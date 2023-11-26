
/* This program is a basic command line interface tool that aspires to demonstrate the structs of Linked List(LL), Stack(ST) and Queue(Q)*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void struct_menu();
void LL_menu();
void ST_menu();
void Q_menu();
int my_get_integer(int range, char *input_message);

/* While the principles demostrated generally apply to many programming languages, our focus will be on C.

One fundamental principle of using structures in C is that nearly every operation is performed through
functions specifically designed to work with the given structure.

Note that each demonstrated struct functions as a set, guaranteeing the absence of duplicate elements within a given struct. 
This ensures that all elements are unique and enables accurate testing for element identification and deletion.

/* Beginning with the linked list, it's a collection of elements called nodes that are organized sequentially(one after the other).
In a basic implementation, a node of a linked list consists of:
1)A pointer that references the same data structure (linked list) and points to the next node in the list.
2)The data part, which can be a simple variable of a primitive type or even another structure.


Below is an illustration of a basic linked list structure with an integer data part and a pointer to the next node*/

struct linked_list{
	int data;
	struct linked_list *next;
};

/* In the above structure, each node contains an integer value stored in the 'data' field and a pointer named 'next' that points to the next node in the linked list.*/


/* As pointed above, to effectively manipulate a linked list,
we require essential functions such as insertion, deletion, printing, and memory deallocation.

However, a common problem occurs when the very definition of a linked list fails to specify the exact insertion point,
or any information on how to insert/delete nodes.


Below are some of the ways someone can INSERT a node inside a linked list structure*/

/* Inserting a node at the end of the LL*/
int LL_insert_at_end(struct linked_list **head, int data)
{
	// Making a pointer to the LL struct and allocating memory for it, if allocation fails we return 0
    struct linked_list *new_node;
    new_node = (struct linked_list *)malloc(sizeof(struct linked_list));
    if (!new_node)
    {
        return 0;
    }
    
    // At this point allocation is successfull.
	// We assign to the data member of the struct, the data that was taken from the call of insert_at_end()
    // We assign to the next pointer of the struct, the value NULL, means it as of now doesn't show to any other node
    new_node->data = data;
    new_node->next = NULL;
    
    // If the list is empty, we make the head of the list be the new_node
    if(*head == NULL)
    {
    	*head = new_node;
	}
	else// If the list isn't empty
	{
		// We make a temporary pointer called temp, to show where head is showing aswell
		struct linked_list *temp = *head;
		
		// Inside a loop, while temp is not NULL, we iterate over each node and check if the data part already exists by comparing the data part given
		// at the call of insert_at_end(), and the data member of each node that temp is currently showing to
		while(temp!=NULL)
		{
			if(temp->data == data) // If the data part already exists, we free the allocated memory of the new_node and return 0
			{
				free(new_node);
				return 2;
			}
			// Making temp be temp->next so as to not have an interminable loop and iterate over each node correctly
			temp=temp->next;
		}
		
		// At this point we know that the data part doesn't already exist in the LL
		
		// We make a temporary pointer called current, to show where head is showing aswell
		struct linked_list *current = *head;
		
		// Inside a loop, while current->next is not NULL(because we need to stop at the last node, not at a NULL node), we iterate over each node
		while(current->next != NULL)
		{
			// Making current be current->next so as to not have an interminable loop and iterate over each node correctly
			current = current->next;
		}
		// At this point it has reached the last node, so we can add the new_node at the end by assigning its value to the next pointer of the current last node
		current->next = new_node;
	}
	// In any case if insertion is successful we return 1
	return 1;
}

/* Inserting a node at the start of the LL*/
int LL_insert_at_start(struct linked_list **head, int data)
{
	// Making a pointer to the LL struct and allocating memory for it, if allocation fails we return 0
	struct linked_list *new_node;
	new_node = (struct linked_list *)malloc(sizeof(struct linked_list));
    if (!new_node)
    {
        return 0;
    }
    // Assigning the data from the function call to the data member of the new_node
    new_node->data = data;
    
    // Checking if the LL is empty or not
    if(*head == NULL)
    {
    	// Making the next pointer of the new_node show to head, so we don't lose the sequence
	    new_node->next = *head;
	    // Making the new_node our new head, so it's the first node in the LL
	    *head = new_node;
		return 1;	
	}
	else// If the LL is not empty
	{
		
		// Loop to see if the data member exists inside the LL
		struct linked_list *temp = *head;
		while(temp!=NULL)
		{
			if(temp->data == data)
			{
				free(new_node);
				return 2;
			}
			temp=temp->next;
		}
		
		// Making the next pointer of the new_node show to head, so we don't lose the sequence
	    new_node->next = *head;
	    // Making the new_node our new head, so it's the first node in the LL, and then returning 1
	    *head = new_node;
		return 1;	
	}
}



/* Inserting a node after an EXISTING element inside the LL*/
int LL_insert_after(struct linked_list **head, int elem, int data)
{
	// Checking if the LL empty, if it is we can't insert anything
	if(*head == NULL)
	{
		return 0;
	}
	
	// At this pointer LL isn't empty, so we need to iterate over every node to see if a data member exists with the value of elem
	// We make a current pointer to head
	struct linked_list *current = *head;
	while(current != NULL)
	{
		// Checking if the data part of the current node, matches the elem taken from the call of insert_after()
		if(current->data == elem)
		{
			// Loop to see if the data member exists inside the LL
			struct linked_list *temp = *head;
			while(temp!=NULL)
			{
				if(temp->data == data)
				{
					return 2;
				}
				temp=temp->next;
			}
			// If it doesn't exist, we first need to create the new_node, malloc memory for it and assign the values
			struct linked_list *new_node = (struct linked_list *)malloc(sizeof(struct linked_list));
			if(!new_node)
			{
				return 3;
			}
			new_node->data = data;
			
			// We now have the new_node and the values, and we need to insert it AFTER the current node, but without losing what is after the current node if there is anything
			// First we make the next pointer of the new_node show to the next pointer of the current node
			new_node->next = current->next;
			// Afterwards now that we have kept the part of the list AFTER the current node, all we need to do is make the current nodes next pointer show to new node and return 1
			current->next = new_node;
			return 1;
		}
		// Making current be current->next in each iteration as to not have an interminable loop
		current = current->next;
	}
	// At this point of the function hasn't returned we can safely assume that we haven't found elem
	return 0;
}

/*Below are some of the ways someone can DELETE a node inside a linked list structure*/

/* Delete first node in LL*/
int LL_delete_at_start(struct linked_list **head, int *data)
{
	// Check if the LL is empty, if it is return 0
	if(*head == NULL)
	{
		return 0;
	}
	// Make a temp pointer to the first node in the LL, in order to keep the memory location to deallocate it and return 1;
	struct linked_list *current = *head;
	// Make the new first node be the next node of the current first node
	*head = (*head)->next;
	// Return the data part of the current node which was the previous first node to *data, in order to keep the value after deletion
	*data = current->data;
	free(current);
	return 1;
}

/* Delete last node in LL*/
int LL_delete_at_end(struct linked_list **head, int *data)
{
	// Check if the LL is empty, if it is return 0
	if(*head == NULL)
	{
		return 0;
	}
	
	// At this point we know LL isn't empty
	
	// We iterate over each node to find the last node so we can delete it
	struct linked_list *current = *head;
	struct linked_list *previous = NULL;
	while(current->next != NULL)
	{
		previous = current;
		current = current->next;
	}
	
	// There are 2 scenarios
	if(previous == NULL) // 1. The LL has only 1 node, so we need to also make head be NULL
	{
		*head = NULL;
	}
	else // 2. There are more than 1 nodes, so we need to make the next pointer of the previous node of the last(current) node show null
	{
		previous->next = NULL;
	}
	// In any case we deallocate memory of last node and also assign to *data the data member of the node to be deleted
	*data = current->data;
	free(current);
	return 1;
}

/* Delete a node of the LL which data member matches the data given at the call of LL_delete_elem()*/
int LL_delete_elem(struct linked_list **head, int elem, int *data)
{
	// There are several scenarios if deleting a node inside an LL by a specific element
	
	// 1. LL is empty, so we can't delete
	if(*head == NULL)
	{
		return 0;
	}
	// At this pointer we know the LL isn't empty, so we search for the elem
	struct linked_list *current = *head;
	struct linked_list *previous = NULL;
	while(current != NULL)
	{
		if(current->data == elem)
		{
			if(previous == NULL) // 2. Elem is found at the start of the LL
			{
				*head = (*head)->next;
			}
			else // 3. Elem is not found at the start of the LL 
			{
				previous->next = current->next;
			}
			*data = current->data;
			free(current);
			return 1;
		}
		previous = current;
		current = current->next;
	}
	
	// At this point, if the execution hasn't returned we can safely asume the element doesn't exist in the LL
	
	// 4. Element doesn't exist inside LL
	return 0;
}

/* Fuction that prints the elements of an LL*/
void LL_print(struct linked_list *head)
{
	struct linked_list *temp = head;
	printf("\n\nCurrent Linked List State: ");
	if(temp == NULL)
		printf("Empty");
	else
	{
		while(temp != NULL)
		{
			printf("%d->", temp->data);
			temp = temp->next;
		}
	}
}

/* Function that deallocates memory basically clearing the Linked List*/
void LL_free(struct linked_list **head)
{
	struct linked_list *previous, *current;
	current = *head;
	if(current == NULL)
	{
		return;
	}
	else
	{
		while(current != NULL)
		{
			previous = current;
			current = current->next;
			free(previous);
		}
	}
}



/* Continuing with the stack structure
A stack is a type of Linked List that follows the principle of Last In First Out (LIFO).
In other words, the last node that is inserted (pushed) into the stack is the first one to be removed (popped).

Push: This operation adds a new node to the beginning of the stack.
Pop: This operation removes an element from the beginning of the stack.

You can visualize these operations by imagining folding clothes from a pile. The last item you put on top is the first one you take off. 

This structure, like all structures, includes helper functions for printing elements and deallocating memory.*/

/* Below is a basic implementation of an ST, basically a Linked List with a different name and different functionality*/
struct stack{
	int data;
	struct stack *next;
};

/* ST_push function*/
int ST_push(struct stack **head, int data)
{
	//Make a pointer to a struct stack and allocate memory for it
	struct stack *new_node;
	new_node = (struct stack *)malloc(sizeof(struct stack));
	if(!new_node)
	{
		return 0;
	}
	
	// Assign to the data member of new_node the data that was inputed from ST_push() call
	new_node->data = data;
	// This node will need to be inserted at the start, thus we first make the next pointer
	// of this new_node to show to the contents of head, then we make head show to the new_node
	new_node->next = *head;
	*head = new_node;
	// If all goes well return 1
	return 1;
}

/* ST_pop function*/
int ST_pop(struct stack **head, int *data)
{
	
	// If the stack is empty, cannot delete, return 0
	if(*head == NULL)
	{
		return 0;
	}
	else
	{
		// Make a temp pointer show to the first element in the ST
		struct stack *temp = *head;
		
		// Assign to the data pointer that was put as argument in the call of ST_pop() the data of temp node that is basically head
		*data = temp->data;
		// Make new head the next node of temp
		*head = temp->next;
		// Deallocate
		free(temp);	
		
		return 1;
	}
}

/* ST_print func*/
void ST_print(struct stack *head)
{
	struct stack *temp = head;
	printf("\n\nCurrent Stack State: ");
	if(temp == NULL)
		printf("Empty");
	else
	{
		while(temp != NULL)
		{
			printf("%d->", temp->data);
			temp = temp->next;
		}
	}
}


/* ST_free func*/
void ST_free(struct stack **head)
{
	struct stack *previous, *current;
	current = *head;
	if(current == NULL)
	{
		return;
	}
	else
	{
		while(current != NULL)
		{
			previous = current;
			current = current->next;
			free(previous);
		}
	}
}

/* Lastly with the Queue
A queue follows the principle of FIFO(First In First Out)
Basically the first element to be inserted(Enqueued) following a sequencial pattern, is also the first to be removed(Dequeued)
A Q doesn't only have an implementation made using pointers

Operations:
Dequeue: The element dequeued is always the first (oldest, leftmost, etc.) one enqueued in the Q.
Enqueue: The element enqeued is always added after the last(newest, rightmost, etc.) element inside the Q

There are two main implementations of a Queue
While both have academic significance, the 2nd implementation is generally preferred in practical scenarios


1) Using a fixed-size array without memory allocation, basically a cercular Q:
In this implementation, we have an array of a fixed size, such as 10. 
We keep track of the first(oldest, leftmost, etc.) element enqueued inside the array and the last(newest, rightmost, etc.) element enqueued. 

Checking to see if the circular Q is full or not is done by seeing if the 'last' variable has a value of 1 less than 'first' (first == last - 1)
In case of last == SIZE_OF_ARRAY - 1, then we need to see if 'first' variable is at place 0 of the array, again if it is this means that the array is full
This can be very smartly done using the modulo operator: return start ==(last + 1) % SIZE_OF_ARRAY

USAGE OF (return start ==(last + 1) % SIZE_OF_ARRAY)(Considering SIZE_OF_ARRAY = 5):

Case 1: Q is not full:
first = 0, last = 3
first ==(last + 1) % SIZE_OF_ARRAY: first == (3 + 1) % 5 -> 0 == 4 % 5 -> 0 == 4 = FALSE
In this case, there are still available places in the circular Q, so it is not full.


Case 2: Queue is full, 'first' is not at the first index of the array:
first = 2, last = 4
first ==(last + 1) % SIZE_OF_ARRAY: first ==(4 + 1) % 5 ->  0 == 5 % 5 = 0 == 0 = TRUE
Since the result is 0 and 'first' is at index 2 
it indicates that the circular queue is full because there are no 
available places before 'first', after 'first', and before 'last'.

Case 3: Queue is full, 'last' is at the last index
first = 0, finish = 4
first ==(last + 1) % SIZE_OF_ARRAY: first == (4 + 1) % 5 -> first ==  5 % 5 -> 0 == 0 = TRUE
In this case, 'finish' is at the last index of the array. 
We need to check if 'start' is at index 0 to determine if the queue is full.
If first was not at index 0, then this wouldn't ever evaluate to TRUE, thus the stack isn't full

This circular behavior gives rise to the term "circular queue".*/

/*
2) Implementing the Q by using a linked list, and keeping track of the first and last node with a 'first' and 'last' pointer
These pointers are not part of the Q structure, but are (struct queue *) initialized before using the Q
*/

/* The second implementation is what will be demonstrated here*/

/* Below is the structure of a Q, basically a Linked List with a different name and functionality*/

struct queue{
	int data;
	struct queue *next;
};

/* Q_enqueue function*/
int Q_enqueue(struct queue **first, struct queue **last, int data)
{
	// Initialization of new_node and memory allocation
	struct queue *new_node;
	new_node = (struct queue *)malloc(sizeof(struct queue));
	if(!new_node)
	{
		return 0;
	}
	
	// Assign to the data member of new_node the data that was inputed from Q_enqueue() call
	// Making the next pointer of new_node be NULL
	new_node->data = data;
	new_node->next = NULL;
	
	
	if(*last == NULL)// If the Q is empty, we make 'first' AND 'last' be new_node
	{
		*last = new_node;
		*first = new_node;
	}
	else // If the Q isn't empty
	{
		// Make new_node the next of that 'last' pointer
		(*last)->next = new_node;
		// Make the new_node be the current(new) 'last'
		*last = new_node;
	}
	return 1;
}


/* Q_dequeue function*/
int Q_dequeue(struct queue **first, struct queue **last, int *data)
{	
	// Making the current pointer hold the current first pointer
	struct queue *current = *first;
	
	if(*first == NULL)// If queue is empty, we don't delete anything and return 0
	{
		return 0;
	}
	else if(*first == *last)// If this evaluates to TRUE, it means the Q has only 1 node
	{
		// Set 'first' and 'last' pointers to NULL
		*first = NULL;
		*last = NULL;
	}
	else// Q has more than 1 node
	{
		//set 'first' to the next pointer of the current 'first'
		*first = (*first)->next;
	}
	// Assigning to *data the value of the data member of the current pointer, which is the previous first
	*data = current->data;
	// Deallocating memory of the previous first(current pointer)
	free(current);
	return 1;
}

/* Q_print function*/
void Q_print(struct queue *first)
{
	struct queue *temp = first;
	printf("\n\nCurrent Queue State: ");
	if(temp == NULL)
		printf("Empty");
	else
	{
		while(temp != NULL)
		{
			printf("%d->", temp->data);
			temp = temp->next;
		}
	}
}

/* Q_free function*/
void Q_free(struct queue **first)
{
	struct queue *previous, *current;
	current = *first;
	if(current == NULL)
	{
		return;
	}
	else
	{
		while(current != NULL)
		{
			previous = current;
			current = current->next;
			free(previous);
		}
	}
}


/* MAIN PROGRAM*/
int main(void)
{
	int struct_menu_active = 1;
	int struct_menu_choice;
	
	int LL_menu_active;
	int ST_menu_active;
	int Q_menu_active;
	
	int LL_menu_choice;
	int ST_menu_choice;
	int Q_menu_choice;
	
	int LL_num;
	int LL_elem;
	int LL_outcome;
	int ST_num;
	
	int Q_num;
	
	// Defining head and last and first pointers for the structures, in order to use them later
	struct linked_list *LL_head;
	
	struct stack *ST_head;
	
	struct queue *Q_last;
	struct queue *Q_first;
	
	while(struct_menu_active)
	{
		struct_menu();
		struct_menu();
		struct_menu_choice = my_get_integer(4, "\nChoice");
		switch(struct_menu_choice)
		{
			// No matter the case, after the user
			case 1:
				LL_menu_active = 1;
				LL_head = NULL;
				while(LL_menu_active)
				{
					LL_menu();
					LL_print(LL_head);
					LL_menu_choice = my_get_integer(7, "\nChoice");
					switch(LL_menu_choice)
					{
						case 1:
							LL_num = my_get_integer(-1, "Enter an integer to Insert");
							LL_outcome = LL_insert_at_start(&LL_head, LL_num);
							if(!LL_outcome)
								printf("\nMemory Allocation failed, could not insert %d in the Linked List\n\n", LL_num);
							else if(LL_outcome == 1)
							{
								printf("\nSuccessfully Inserted %d at the start of the Linked List\n\n", LL_num);
							}
							else
								printf("\nCould not Insert %d into the Linked Linked because it already exists\n\n", LL_num);
							system("pause");
							break;
						case 2:
							LL_num = my_get_integer(-1, "Enter an integer to Insert");
							LL_outcome = LL_insert_at_end(&LL_head, LL_num);
							if(LL_outcome == 0)
							{
								printf("\nMemory Allocation failed, could not insert %d in the Linked List\n\n", LL_num);
							}
							else if(LL_outcome == 1)
								printf("\nSuccessfully Inserted %d at the end of the Linked List\n\n", LL_num);
							else
								printf("\nCould not Insert %d into the Linked Linked because it already exists\n\n", LL_num);
							system("pause");
							break;
						case 3:
							LL_elem = my_get_integer(-1, "Enter an existing integer inside the Linked List");
							LL_num = my_get_integer(-1, "Enter an integer to Insert");
							LL_outcome = LL_insert_after(&LL_head, LL_elem, LL_num);
							if(LL_outcome == 0)
							{
								printf("\nCould not find and Insert after element %d\n\n", LL_elem);
							}
							else if(LL_outcome == 1)
							{
								printf("\nSuccessfully Inserted %d after %d into the Linked List\n\n", LL_num, LL_elem);
							}
							else if(LL_outcome == 2)
							{
								printf("\nCould not Insert %d into the Linked Linked because it already exists\n\n", LL_num);
							}
							else
							{
								printf("\nMemory Allocation failed, could not insert %d in the Linked List\n\n", LL_num);
							}
							system("pause");
							break;
						case 4:
							if(LL_delete_at_start(&LL_head, &LL_num))
							{
								printf("\nSuccessfully Deleted %d from the Linked List\n\n", LL_num);
							}
							else
							{
								printf("\nLinked List is Empty, nothing to Delete\n\n");
							}
							system("pause");
							break;
						case 5:
							if(LL_delete_at_end(&LL_head, &LL_num))
							{
								printf("\nSuccessfully Deleted %d from the Linked List\n\n", LL_num);
							}
							else
							{
								printf("\nLinked List is Empty, nothing to Delete\n\n");
							}
							system("pause");
							break;
						case 6:
							LL_elem = my_get_integer(-1, "Enter an Existing element inside the Linked List");
							if(LL_delete_elem(&LL_head, LL_elem, &LL_num))
							{
								printf("\nSuccessfully Deleted %d from the Linked List\n\n", LL_num);
							}
							else
							{
								printf("\nCould not find and delete %d from the Linked List\n\n",LL_elem);
							}
							system("pause");
							break;
						case 7:
							LL_free(&LL_head);
							LL_menu_active = 0;
							break;
					}
				}
				break;
			case 2:
				ST_menu_active = 1;
				ST_head = NULL;
				while(ST_menu_active)
				{
					ST_menu();
					ST_print(ST_head);
					ST_menu_choice = my_get_integer(3, "\nChoice");
					switch(ST_menu_choice)
					{
						case 1:
							ST_num = my_get_integer(-1, "Enter an integer to Push");
							if(ST_push(&ST_head, ST_num))
								printf("\nSuccessfully Pushed %d into the Stack\n\n", ST_num);
							else
								printf("\nSomething went wrong\n\n");
							system("pause");
							break;
						case 2:
							if(ST_pop(&ST_head, &ST_num))
								printf("\nSuccessfully Popped %d from the stack\n\n",ST_num);
							else
								printf("\nStack is Empty, could not Pop anything\n\n");
							system("pause");
							break;
						case 3:
							ST_free(&ST_head);
							ST_menu_active = 0;
							break;
					}
				}
				break;
			case 3:
				Q_menu_active = 1;
				Q_last = NULL;
				Q_first = NULL;
				while(Q_menu_active)
				{
					Q_menu();
					Q_print(Q_first);
					Q_menu_choice = my_get_integer(3, "\nChoice");
					switch(Q_menu_choice)
					{
						case 1:
							Q_num = my_get_integer(-1, "Enter an integer to Enqueue");
							if(Q_enqueue(&Q_first, &Q_last, Q_num))
								printf("\nSuccessfully Enqueued %d in the Queue\n\n", Q_num);
							else
								printf("\nSomething went wrong\n\n");
							system("pause");
							break;
						case 2:
							if(Q_dequeue(&Q_first, &Q_last, &Q_num))
								printf("\nSuccessfully Dequeued %d from the Queue\n\n", Q_num);
							else
								printf("\nQueue is Empty, could not Dequeue anything\n\n");
							system("pause");
							break;
						case 3:
							Q_free(&Q_first);
							Q_menu_active = 0;
							break;
					}
				}
				break;
			case 4:
				printf("\nProgram execution finished\n");
				struct_menu_active = 0;
				break;
		}
	}

	return 0;
}


void struct_menu()
{
	system("cls");
	int i;
	/* Basic graphical interface for the main menu*/
	printf("\n%c", 201);
	for(i=1;i<19;i++)
		printf("%c", 205);
	printf("%c", 187);
	
	printf("\n%c",186);
	for(i=1;i<4;i++)
		printf(" ");
	printf("Structs Menu");
	for(i=1;i<4;i++)
		printf(" ");
	printf("%c", 186);
	
	printf("\n%c", 200);
	for(i=1;i<19;i++)
		printf("%c", 205);
	printf("%c", 188);
	printf("\n1. Linked List\n2. Stack\n3. Queue\n4. Exit");
}

void LL_menu()
{
	system("cls");
	int i;
	/* Basic graphical interface for the Linked List Menu*/
	printf("\n%c", 201);
	for(i=1;i<19;i++)
		printf("%c", 205);
	printf("%c", 187);
	
	printf("\n%c",186);
	for(i=1;i<2;i++)
		printf(" ");
	printf("Linked List Menu");
	for(i=1;i<2;i++)
		printf(" ");
	printf("%c", 186);
	
	printf("\n%c", 200);
	for(i=1;i<19;i++)
		printf("%c", 205);
	printf("%c", 188);
	printf("\n1. Insert at start\n2. Insert at end\n3. Insert after elem\n4. Delete at start\n5. Delete at end\n6. Delete elem\n7. Back to Struct Menu(Clears Linked List)");
}

void ST_menu()
{
	system("cls");
	int i;
	/* Basic graphical interface for the Stack Menu*/
	printf("\n%c", 201);
	for(i=1;i<15;i++)
		printf("%c", 205);
	printf("%c", 187);
	
	printf("\n%c",186);
	for(i=1;i<3;i++)
		printf(" ");
	printf("Stack Menu");
	for(i=1;i<3;i++)
		printf(" ");
	printf("%c", 186);
	
	printf("\n%c", 200);
	for(i=1;i<15;i++)
		printf("%c", 205);
	printf("%c", 188);
	printf("\n1. Push\n2. Pop\n3. Back to Struct Menu(Clears Stack)");
}

void Q_menu()
{
	system("cls");
	int i;
	/* Basic graphical interface for the Queue Menu*/
	printf("\n%c", 201);
	for(i=1;i<15;i++)
		printf("%c", 205);
	printf("%c", 187);
	
	printf("\n%c",186);
	for(i=1;i<3;i++)
		printf(" ");
	printf("Queue Menu");
	for(i=1;i<3;i++)
		printf(" ");
	printf("%c", 186);
	
	printf("\n%c", 200);
	for(i=1;i<15;i++)
		printf("%c", 205);
	printf("%c", 188);
	printf("\n1. Enqueue\n2. Dequeue\n3. Back to Struct Menu(Clears Queue)");
}

/* Function to get an integer value only */
int my_get_integer(int range, char *input_message)
{
 /* Everything done in this function is done using stdlib functions
	I could use string.h or ctype.h but where is the fun in that?*/
	int i, c, number, is_valid;
	char buffer[12];
	
	// Checking the range value that was put into the Func as an argument
	// If it is below 0 or above the standard INT_MAX value of (usually 2147483647), then the range is converted to INT_MAX
	if(range <= 0 || range > INT_MAX)
		range = INT_MAX;
		
	do
	{	
		
		// Asking for input and using fgets to store it into a temporary array of 12 chars
		// 12 because the INT_MAX can only be up to 2147483647 which is 10 characters but in the string has to also be the null terminating character '\0'
		// BUT also fgets reads '\n' aswell, thus it needs to be 1 more character size to correctly read everything
		printf("\n%s in range (1,%d): ", input_message, range);
		fgets(buffer, sizeof(buffer), stdin);
		
		// Iterating over the chars in the buffer array until we see a null terminating char('\0')
		// If a new line char('\n') is found, we turn it into the null terminating char to remove it from the array
		// We also make new_line_exists bool to 1 for later use
		int new_line_exists = 0;
		for(i=0;buffer[i] != '\0';i++)
		{
			if(buffer[i] == '\n')
			{
				new_line_exists = 1;
				buffer[i] = '\0';
				break;
			}
		}
        
        // At this point, new_line_exists will have a number of 1 or 0, representing the appearance of a '\n' char in the array
        // If a '\n' char actually existed in the array, it means that fgets() has successfully consumed everything even the '\n' from the stdin and stored them into buffer
		// which in turn means we don't need to clear the stdin
        // On the other hand if '\n' didn't exist it didn't have enough space to include it thus stdin is not empty
        if(!new_line_exists)
        {
        	int c;
        	while((c = getchar()) != '\n' && c != EOF);
		}
        	
		// Assuming the number is valid at the start of the iteration
		
		// Iterating until we reach the null terminating character in the buffer
		
		// Each buffer[i] represents a character in the buffer array (e.g., '1')
		// Each character in C has a corresponding decimal value, which is then converted
		// to binary and further into machine code
		
		// These decimal values are known as ASCII values, ranging from 0 to 255 (0 - 2^8 - 1, 1 byte size including 0)
		// However, the Unicode standard exists to represent a broader range of characters
		
		// '1' is a character, while 1 is an integer; therefore, '1' has a different ASCII value than 1
		
		// We check if the character (e.g., '1') falls within the range of 48 to 57, inclusive
		// This range corresponds to the characters '0', '1', ..., '9'
		
		// If we encounter any character outside this range, it indicates an invalid numbers
        is_valid = 1;
	    for (i = 0; buffer[i] != '\0'; i++)
		{
	        if ((buffer[i] < 48 || buffer[i] > 57))
			{
	            is_valid = 0;
	            break;
	        }
	    }
	    
		// Performing ASCII math
		// Initializing the number variable to 0 to use it as a sum variable
		// Iterating through the character array
		// In this code, we determine the place value of each digit based on its position in the iteration.
		// At each iteration, we multiply the number by 10 to shift its place value
		// To obtain the actual digit value, we subtract the ASCII value of '0' from the ASCII value of the buffer[i] character
		// For example, if the user inputs '12':
		// - First iteration: number = 0 * 10 = 0, then number += ('1' - '0'), number += (49 - 48), number += 1, so the current number is 1
		// - Second iteration: number = 1 * 10 = 10, then number += ('2' - '0'), number += (50 - 48), number += 2, so the current number is 12
		// This process allows us to convert the character array into its corresponding integer value
		
	    number = 0;
	    for(i=0;buffer[i] != '\0';i++)
	    {
	    	number *= 10;
	    	number += (buffer[i] - '0');
		}
		
		// Checking if the number is in the correct range
	    if(number <= 0 || number > range)
            is_valid = 0;
        
        // if it isn't valid, show a message
		if(!is_valid)
		{
			printf("\nInvalid input\n");
            system("pause");
		}
	}
	while(!is_valid);
	
	return number;
}

