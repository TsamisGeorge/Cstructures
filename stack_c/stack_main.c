#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

main()
{
	int choice,elem,i;
	STACK st; // object of type struct stack
	
	ST_init(&st); //init the object by passing its address inside ST_init()
	
	while(1)
	{
		system("cls"); //clearing the screen of the output at the start of each menu call
		printf("Menu of the stack:\n");
		printf("_________________\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Print\n");
		printf("4. Exit\n");
		printf("Choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				fflush(stdin);
				printf("\nGive an elem: ");
				scanf("%d",&elem);
				if(ST_push(&st,elem))
					printf("Successful push.\n");
				else
					printf("Unsuccessful push, the stack is full.\n");
				break;
			case 2:
				if(ST_pop(&st,&elem))
					printf("Successfully popped the element %d.\n", elem);
				else
					printf("Unsuccessful pop, the stack is empty.\n");
				break;
			case 3:
				printf("The stack has %d elements.\n",st.top+1);
				for(i=0;i<= st.top;i++)
				{
					printf("[%d]",st.array[i]);
				}
				break;
			case 4:
				printf("Exited.");
				exit(0);
			default:
				printf("Invalid input.\n");
		}
		printf("\n\n");
		system("pause");
	}
}
