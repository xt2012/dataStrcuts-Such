#include <stdio.h>
#include <stdlib.h>

void Push( int value, int** data, int* topControler )
{
	*data = realloc(*data, sizeof(int) * (*topControler + 1));	
	
	(*data)[*topControler] = value;
	(*topControler)++;
}



int Sizestr( int* topControler )
{
	//IMPLEMENT STRUCT-BASED DATA STRUCTURE TO HOLD BOTH DATA
	//AND ITS RESPECTIVE TOPCONTROLER

	return *topControler;
	
}

int Size ( int* data ){

	return sizeof(data)/sizeof(int);
	
}

int main()
{
	int* data = NULL;
	int topControler = 0;
	//Push
	//Pop
	//Peek
	//Clean
	//List
	//Size

	Push(5, &data, &topControler);

	Push(10, &data, &topControler);
	
	Push(20, &data, &topControler);

	Push(80, &data, &topControler);

	Push(20, &data, &topControler);
	printf("TOP: %d\n", topControler);

	printf("ELEMENTS IN DATA: %d\n", topControler);
	printf("SIZE OF DATA: %ld bytes\n", sizeof(int) * topControler );

    for (int i = 0; i < topControler; i++) {
        printf("%d\n", data[i]);
    }
	free(data);
	return 0;
}
