#include <stdio.h>
#include <stdlib.h>

struct ponto{
    float x;
    float y;
    struct ponto *prox;
};

typedef struct ponto Ponto;

Ponto *listaPontos; //1 struct 

// 	    p	       listaPontos	       *listaPontos
//		x				5		    		7
//		y				1			 		2
// 	  *prox		  prox=listaPontos   *(*listaPontos)
//
//

void add(float x, float y){
    Ponto *p = (Ponto*) malloc(sizeof(Ponto)); //just refers to a place in memory where this second struct is
    p->x = x;
    p->y = y;
    p->prox = listaPontos; //pointer in p points to listaPontos
    listaPontos = p; //address of listaPontos=address of p listaPontos IS p
}
//listaPontos->x listaPontos->y
//listaPontos->prox->x //listaPontos->prox->y



int main(){
    
    add(1,5);//1 is stored in p->x and 5 is stored in p->y   prox in p points to listaPontos and listaPontos is p
    add(2,7);
    add(5,3);


    printf("%.0f %.0f\n ",listaPontos->prox->prox->x, listaPontos->prox->prox->y);
    
    printf("%.0f %.0f\n",listaPontos->prox->x, listaPontos->prox->y);


    printf("%.0f %.0f\n",listaPontos->x, listaPontos->y);
    return 0;
}
