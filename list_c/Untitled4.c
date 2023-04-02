#include <stdio.h>

main()
{
	int *pointer1;
	int **pointer2;
	pointer2 = &pointer1;
	
	printf("%d", *pointer2);
}
