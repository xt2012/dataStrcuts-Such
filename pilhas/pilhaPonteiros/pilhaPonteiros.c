#include <stdio.h>
#include <stdlib.h>

//int indexTopControler=0;

void Push( int value, int** data )
{
//    printf("%d\n", **(data));


    *(data)=realloc(*(data), sizeof(int)+sizeof(*(data)) );
    **(data)=value;
	//size if available here ^
    //Size()

//    printf("%d\n", **(data) );
//    printf("%d\n", *(data[0]) );
}


int Size( int* data )
{

	int counter = 0;
      
    for( int i = sizeof(int); i < sizeof(data); i=i+sizeof(int) ){
 //     printf("%d", *(data+counter));    
      counter++;
    }
	return counter;

}


int main()
{
	int* data = malloc(sizeof(int));

	//Push
	//Pop
	//Peek
	//Clean
	//List
	//Size
	Push(5, &data);
	Push(7, &data);
    
    //printf("%d",data[0]);
    //printf("%d",data[1]);
    
//    Size(data);	

	printf("%d\n", Size(data));
	printf("%d\n%d\n", *(data), *(data+1) );

	return 0;
}
