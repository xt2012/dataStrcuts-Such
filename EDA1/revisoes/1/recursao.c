#include <stdio.h>
#include <stdlib.h>


int sum( int *A, int n ){
    if( n == 0 ) return 0;
    
    return sum(A, n-1) + A[n-1];

}

int max(int a, int b) {
    return (a > b) ? a : b;
}


int valorMax( int *A, int n ){
    if(n<1) return 0;
    return max(A[n], valorMax(A, n-1));

}

int main(){
    int A[]={1,2,3,4,90,6,7,8,9,10};

    printf("%d", valorMax(A, 10));




    return 0;
}
