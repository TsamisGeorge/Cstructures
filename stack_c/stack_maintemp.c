#include <stdio.h>
#include <stdlib.h>
#include "stacktemp.h"

main()
{
	int choice,i;
	STACK st; // object of type struct stack
	ST_init(&st); //init the object by passing its address inside ST_init()
	ELEM elem;
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
				printf("\nName of the student: ");
				fflush(stdin);
				gets(elem.name);
				printf("\nGrade of the student: ");
				scanf("%d",&elem.grade);
				if(ST_push(&st,elem))
					printf("Successful push.\n");
				else
					printf("Unsuccessful push, the stack is full.\n");
				break;
			case 2:
				if(ST_pop(&st,&elem))
					printf("Successfully popped the element %s(%d).\n", elem.name, elem.grade);
				else
					printf("Unsuccessful pop, the stack is empty.\n");
				break;
			case 3:
				printf("The stack has %d elements.\n",st.top+1);
				for(i=0;i<= st.top;i++)
				{
					printf("%s",st.array[i].name);
					printf(": %d",st.array[i].grade);
					printf("\n");
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
