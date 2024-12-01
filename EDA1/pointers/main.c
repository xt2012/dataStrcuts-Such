#include "variaveis.h"
#include <string.h>
void f(int a){
    printf("%d\n", a);
}

void f1(int a){
    printf("%d\n", a+1);
}

extern int var1;
int var2;

int main(int argc, char **argv){
    /*
    void (*fp)(int);

    if(argc > 1 && strcmp(argv[1], "f") == 0){
        fp = &f;
    }else{
        fp = &f1;
    }
   
    (*fp)(10);

    void (*funcoes[2])(int) = { &f, &f1 };

    for(int i = 0; i<2; i++){
        (*funcoes[i])(i);
    }
   */ 
    printf("%d\n", var1);
    printf("%d\n", retornaVar1());
    printf("%d\n", retornaVar2());

    var1=4;
    printf("%d\n", var1);
    printf("%d\n", retornaVar1());



    return 0;




}
