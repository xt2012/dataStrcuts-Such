#include <stdio.h>
#include <stdlib.h>

typedef struct celula{

    int dado;
    struct celula *prox;

}celula;

void divide_lista (celula *l, celula *l1, celula *l2);


void alocar_prox(celula *head, int dado){
    celula *temp = NULL;
    temp = head;

    for(int i = 0; i<10 && temp->prox!=NULL; i++)
        temp=temp->prox;

    celula *celulaNova = malloc(sizeof(celula));
    celulaNova->dado = dado;
    celulaNova->prox=NULL;
    temp->prox=celulaNova;


}

void imprimir_lista(celula *l, celula *l1, celula *l2){
    celula *temp = l->prox;
    while(temp){
        printf("%d\n", temp->dado);
        temp=temp->prox;
    }
    printf("\nDados L1\n");
    temp = l1->prox;
    while(temp){
        printf("%d\n", temp->dado);
        temp=temp->prox;
    }
    printf("\nDados L2\n");
    temp = l2->prox;
        while(temp){
            printf("%d\n", temp->dado);
            temp=temp->prox;
        }
}

void divide_lista (celula *l, celula *l1, celula *l2){
    celula *temp = l->prox;
    celula *l1_tail = l1;
    celula *l2_tail = l2;

    while (temp!=NULL){
        if(temp->dado % 2 == 0){ 
            l1_tail->prox = temp;
            l1_tail=l1_tail->prox;
        }else{
            l2_tail->prox = temp;
            l2_tail=l2_tail->prox;
        }
        temp=temp->prox;
    }
    l1_tail->prox=NULL;
    l2_tail->prox=NULL;
    
}


int main(){
    celula *head = malloc(sizeof(celula));
    head->prox=NULL;
    celula *l1 = malloc(sizeof(celula));
    celula *l2 = malloc(sizeof(celula));
    l1->prox = NULL;
    l2->prox = NULL;

    head->dado = 2;
    alocar_prox(head, 4);
    alocar_prox(head, 2);
    alocar_prox(head, 28);
    alocar_prox(head, 10);
    alocar_prox(head, 5);
    alocar_prox(head, 3);
    alocar_prox(head, 1);
    alocar_prox(head, 23);
//    printf("%d", head->prox->dado);
//    printf("%d", head->prox->prox->dado);

    divide_lista(head, l1, l2);
//   imprimir_lista(head, l1, l2); 
}
