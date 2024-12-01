#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* str = "* + 7 * * 4 6 + 8 9 5";
int i = 0;

int eval(){
    int x =0;

    while(str[i]==' ') i++;

    if(str[i] == '*'){
        i++;
        return eval() * eval();
    }
    if(str[i] == '+'){
        i++;
        return eval() + eval();
    }


    while(str[i] >= '0' && str[i] <= '9'){
        
        x = 10 * x + (str[i++] - '0');

    }
    return x;

}


int main(){
    printf("%d", eval()); 
    return 0;
}
