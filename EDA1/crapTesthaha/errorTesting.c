#include <stdio.h>

int find1(int x, int valores[], int n){
    int k=0, found=0;
    while(k<n && found!=1){
        if( valores[k]==x ) found=1;
        ++k;
    }

    return k;
        
}


int find2(int x, int valores[], int n){
    int k = n-1;

    while(k>=0 && valores[k]!=x) k--;
        
    return k;

}

//remover por indice ou por valor?
int remove(int k, int valores[], int n){ //indice
    
    for(int j = n-1; j>=0; --j)1
    

}

int main(){

    int valores[5]={0,1,2,3,4};

    printf("%d\n", find2(4, valores, 5));
    return 0;
}
