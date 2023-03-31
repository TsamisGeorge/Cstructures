#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
int main(void)
{
	QUEUE qu;
	QU_init(&qu);
	elem x;
	int choice, i;
	while(1)
	{
		printf("\n|Queue Menu|\n");
		printf("____________\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Print\n");
		printf("4. Exit\n");
		printf("Choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("\nGive an element: ");
				scanf("%d",&x);
				if(QU_enqueue(&qu, x))
					printf("\nEnqueued the element: %d.", x);
				else
					printf("\nFailed the enqueue, stack is full.");
				break;
			case 2:
				if(QU_dequeue(&qu, &x))
					printf("\nDequeued the element: %d", x);
				else
					printf("\nFailed to dequeue stack is empty.");
				break;
			case 3:
				printf("\n");
				for(i=0;i<=qu.finish;i++)
				{
					printf("[%-2d]",qu.array[i]);	
				}
				break;
			case 4:
				printf("\nExited.");
				exit(0);
			default:
				printf("\nInvalid input.");
		}
	}
}
