#include <stdio.h>
#include <stdlib.h>

int main(){
	float *p1, *p2;//the compiler itself allocated a memory space large enough to store an
//	address of type float

	//p1 = pointerReturnedByMalloc  	p1=p2
	p1 = (float *)malloc(10*sizeof(float));//p1 e p2 acabam sendo vetores por apontarem para um espaco de memoria reservado para 10 floats
	//vetor nada mais e do que um ponteiro 
	float vetores[10]; //vetores[1] aponta para o endereço de memoria que corresponde ao index 1
		
	printf("%p", p1);

	if (p1==NULL){ return 1; }
	
	p2 = (float *)calloc(10, sizeof(float));
	if (p2==NULL) { return 1; } 

	for(int i=0; i<10; i++)
	{
		
		printf("\n%f", *(p1+i));
			
		printf("\nPosicao %i do p1: %f", i, p1[i]);
		printf("\nPosicao %i do p2: %f", i, p2[i]);
			

	}

	return 0;
	
}		
