#include <stdio.h>
#include <stdlib.h>

int main()
{
	int **p, i=0, j=0;
	//find myself a space in memory capable of holding a pointer to a pointer that is, an
	//address that will hold on address, this address holds an address that will hold an int; 
	
	p = (int **)malloc(2*sizeof(int *));
	printf("%zu", sizeof(int *));

	printf("%zu\n", sizeof(int **));
	
	for(i=0;i<2;i++)
	{
		p[i]=(int *)malloc(2*sizeof(int));
		
		for(j=0;j<2;j++)
		{
			
			p[i][j]=i+j;

			printf("%d\n", p[i][j]);
		
		}

	}




	return 0;
}
