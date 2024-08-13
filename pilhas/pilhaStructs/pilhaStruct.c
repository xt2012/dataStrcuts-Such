#include <stdio.h>
#include <stdlib.h>

struct dataStruct{
    char charStruct;
    struct dataStruct* prev;
    //could possibly have a next here too, do it later and adapt push instr.
};

int Push (struct dataStruct** dados, int* top, char c){
    
    if(*dados==NULL){
    *dados= (struct dataStruct *)malloc(sizeof(struct dataStruct));
        dados[*top]->charStruct=c;
        dados[*top]->prev=NULL;
        return 0;
    }
       if(dados[*top]->prev==NULL){} //create new one to be the next and assign dados to be the previous

    
}

int main(){
    struct dataStruct* dados = NULL;//pass the address of this to other functions
    int top = 0;

    //push
    //size
    //peek

    Push(&dados, &top, 'j');
    Push(&dados, &top, 'g');

    printf("%c", dados[0].charStruct);
    printf("%c", dados[1].charStruct);

    for(int i=0; i<=top; i++){
    printf("%c", dados[i].charStruct);
    }
    return 0;
}
