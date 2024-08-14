#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10
//tamanho max: dez posicoes ||  tipo da pilha: inteiro

int topo = 0;
int aux = 0;
int pilha[10];

int Size_Pilha()
{
	return topo;
}

int Pop_Pilha()
{
	int guardarPilhaNoTopo;	
	//if ( (topo-1) == 0 ) {	return 0;	}//pilha vazia	
//	else{
			topo--;		
			guardarPilhaNoTopo=pilha[topo];
			pilha[topo]=0;
			return guardarPilhaNoTopo;
//		}
}

void Push_Pilha(int valor)
{
	if ( topo < TAMANHO ) {	
		pilha[topo] = valor;
		topo++;
	}
}

void List_Pilha()
{

	for( int i = 0; i < topo; i++ ){
		printf("valor em %d:	%d\n", (i+1),
				pilha[topo -1 - i]);	
			}
	printf("%d", pilha[2]);

}

int Peek(int index)
{
	if	(index > -1 && index < topo){
	
		return pilha[index];
		
	}else	{ 	return 0;	}
}

void Clear_Pilha()
{
	for(int i=topo;i>-1;i--){
		
		pilha[i-1]=0;
		topo=0;
	}
}

int main()
{
	char op = ' ';
	//A - adiciona algo
	//R - remover algo
	//S - verificar o tamanho atual
	//L - listar
	//X - sair
	
	Push_Pilha(1);
	Push_Pilha(2);
	Push_Pilha(3);
	while(op != 'X')
	{

		scanf(" %c", &op);
		if	(op=='A' || op=='a'){
				scanf("%d", &aux);
				Push_Pilha(aux);

		}else if 	( op=='R' || op=='r' ){
		
			printf("%d\n",Pop_Pilha());

		}else if	( op=='S' || op=='s' ){
		
			printf("%d", Size_Pilha());		

		}else if	(op == 'L' || op == 'l'){

			List_Pilha();
		}else if	( op == 'C' || op == 'c' ){

			Clear_Pilha();

		}else if	( op == 'P' || op == 'p' ){
			scanf(" %d", &aux);
			printf("%d", Peek(aux));

		}else{
			
			fprintf(stderr, "ERRO: OPERAÇÃO INVALIDA");
			return 1;
		}
	}	

	return 0;
}




