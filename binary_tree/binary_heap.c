#include "binary_heap.h"
#include <stdio.h>
#include <stdlib.h>

void HEAP_init(HEAP *heap)
{
	heap -> N = 0;
}

void swap(elem *x, elem *y)
{
	elem temp;
	
	temp = *x;
	*x = *y;
	*y = temp;
}


int HEAP_insert(HEAP *heap, elem x)
{
	int parent_pos, current_pos;
	if(heap -> N == MAX_SIZE)
		return False;
		//otherwise if no size limit, set it as N pos
	else
	{
		//put the elem in the last place of the tree
		heap -> data[heap -> N] = x;
		
		//the last pos of the array is raised by 1 
		heap -> N ++;
		
		//getting the value of current N as current_pos
		current_pos = heap -> N - 1 ;
		
		while(current_pos > 0)
		{
			//getting the value of the parent of the current_pos node
			parent_pos = (current_pos - 1) / 2;
			if(heap -> data[current_pos] < heap -> data[parent_pos])
			{
				//swap
				swap(&heap -> data[current_pos], &heap -> data[parent_pos]);
				current_pos = parent_pos;
			}
			else
				break;
		}
		return True;
	} 
}

int HEAP_delete(HEAP *heap, elem *x)
{
	int current_pos, left_pos, right_pos, pos;
	if(heap -> N == 0)
		return False;
	//check
	
	*x = heap -> data[0];
	//check
	
	heap -> data[0] = heap -> data[heap -> N - 1];
	heap -> N--;
	//check
	
	current_pos = 0;
	//check
	
	while(current_pos < heap -> N)
	{
		//check
		
		left_pos = 2 * current_pos + 1;
		right_pos = 2 * current_pos + 2;
			
		if(left_pos >= heap ->N)
			left_pos = -1;
		if(right_pos >= heap -> N)
			right_pos = -1;
		
		
		if(left_pos == -1 && right_pos == -1)
			break;
		
		else if(left_pos != -1 && right_pos == -1)
		{
			if(heap -> data[current_pos] < heap -> data[left_pos])
			{
				swap(&heap -> data[current_pos], &heap -> data[left_pos]);
				current_pos = left_pos;
			}
			else
				break;
		}
		
		else 
		{
			
			if(heap -> data[left_pos] > heap -> data[right_pos])
				pos = left_pos;
			else
				pos = right_pos;
			
			
			if(heap -> data[current_pos] < heap -> data[pos])
			{
				swap(&heap -> data[current_pos], &heap -> data[pos]);
				current_pos = pos;
			}
			else
				break;
		}
	}	
}
