#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entry_list.h"

main()
{
	int choice;
	char c;
	LIST_PTR list;
	LL_init(&list);
	elem student;
	char buffer[80];
	while(1)
	{
		printf("\nMenu");
		printf("\n____");
		printf("\n1. Insert entry");
		printf("\n2. Delete entry");
		printf("\n3. Print entries");
		printf("\n4. Average");
		printf("\n5. Students that passed");
		printf("\n6. Exit");
		printf("\nChoice: ");
		scanf("%d", &choice);
		scanf("%*[^\n]");
		switch(choice)
		{
			case 1:
				printf("\nGive the name of the student: ");
				scanf("%*[\n]");
				fgets(student.name, 80, stdin);
				student.name[strcspn(student.name, "\n")] = '\0';
				printf("\nGive the grade of the student: ");
				scanf("%d",&student.grade);
				LL_insert(&list, student);
				printf("\nInsertion was successful.");		
				break;
			case 2:
				printf("\nGive the name of the student that is about to be deleted: ");
				scanf("%*[\n]");
				fgets(buffer, 80, stdin);
				buffer[strcspn(buffer, "\n")] = '\0';
				if(LL_delete_student(&list, buffer))
				{
					printf("\nSuccessfully deleted %s.", buffer);
				}
				else
				{
					printf("\n%s is not a student.", buffer);
				}
				break;
			case 3:
				LL_print(list);
				break;
			case 4:
				printf("\nAverage grades of the students: %.2lf", LL_average(list));
				break;
			case 5:
				printf("\nStudents that passed the class: %d",LL_students_that_passed(list));
				break;
			case 6:
				printf("\nExited.");	
				exit(0);
				break;
			default:
				printf("\nInvalid input");
				break;
		}
	}
}
