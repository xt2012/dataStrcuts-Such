#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define exch(A, B) do { typeof(A) temp = (A); (A) = (B); (B) = temp; } while(0)
#define exch(A, B) { typeof(A) temp = (A); (A) = (B); (B) = temp; }


void insertionSortO( int *v, int l, int r )
{
    int temp, i, j;
    for(i = l; i<=r; i++){//n
        temp = v[i];

        for(j = i; j>l && temp < v[j-1]; j--){
        //(n-1),(n-2)
            v[j]=v[j-1];
        }
        v[j]=temp;
    }
}

void insertionSort( int *v, int l, int r )
{
    int i, j;
    for(i = l; i<=r; i++){//n
        for(j = i; j>l && v[j] < v[j-1]; j--){
        //(n-1),(n-2)
            exch(v[j], v[j-1]);
        }
    }
}

void bubbleSort( int *v, int l, int r ){
    while(r>l){
        for(int j = l; j<=r && v[j]<v[j-1] ; j++){
           exch(v[j], v[j-1]) ;
        }
        r--;
    }

}

void shellSort( int *v, int l, int r){
    int i,j,temp, h=1;
    while(h < (l+r-1)/3)
        h=h*3+1;

    while(h>=1){
        for(i =l+h; i<=r; i++){
            temp = v[i];
            for(j = i; j>=l+h && temp<v[j-h]; j-=h){
                v[j]=v[j-h];
            }
            v[j]=temp;
        }
        h=h/3;
    }
}

void merge( int *v, int l, int m, int r ){
    int tam = (r+1-l);
    int *aux = malloc(sizeof(int) * tam);
    int i,j,k;
    i=l; j=m+1; k=0;
    
    while(i<=m && j<=r){
        
        if(v[i]<=v[j]){
            aux[k++]=v[i++];
        }else{
            aux[k++]=v[j++];
        }
    
    }

    while(i<=m) aux[k++]=v[i++];
    while(j<=r) aux[k++]=v[j++];

    for(i=l, k=0; i<=r; i++,k++){
        v[i]=aux[k];
    }
    
    free(aux);
}

void mergeSort( int *v, int l, int r  ){
    if(l>=r) return;
    int m = (l+r) >> 1;

    mergeSort(v, l, m);
    mergeSort(v, m+1, r);
    merge(v, l, m, r);

}



int main(int argc, char* argv[]){
    int size=100000;
    int r = size-1;
    int *v = malloc(sizeof(int)*size);

    //populating
    for(int i = 0; i<size; i++){
        v[i]=size-i;
    }
    

    if(strcmp(argv[1],"shell") == 0){
        shellSort(v, 0, r);
    }else if(strcmp(argv[1],"insert")==0){
        insertionSort(v, 0, r);
    }else if(strcmp(argv[1],"merge") == 0){
        mergeSort(v, 0, r);
    }

    for(int i = 0; i<size; i++){
        printf("%d\n",v[i]);
    }
    

}



