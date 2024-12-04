#include <stdio.h>
#include <stdlib.h>
#define exch(A,B){int temp = A; A=B; B=temp;};

void selectionSort(int *v, int l, int r){
    int menor;
    for(int i=l; i<r; i++){
        menor = i;
        for(int j = i+1; j<=r; j++){
            if(v[j]<v[menor]) 
                menor = j;
        }
        if(i!=menor){
            exch(v[i],v[menor]);
        }
    }
}

void bubbleSort(int *v, int l, int r){
    int swap=1;
    while(r>l && swap){
        swap=0;
        for(int j=l; j<r; j++){
            if(v[j]>v[j+1]){
                exch(v[j],v[j+1]);
                swap=1;
            }
        }
        r--;
    }
}


void insertionSort(int *v, int l, int r){
    
}

int quick(int *v, int l, int r){
    int pivot = v[r];
    int i=l-1,j=r;
    while(i<j){
        while(v[++i]<=pivot && i<r);
        while(v[--j]>=pivot && j>l);
        if(i<j)    exch(v[i],v[j]);
    }

    exch(v[i],v[r]);

    return i;
}

void quickSort(int *v, int l, int r){
    if( r <= l  ) return;
        

    exch(v[(r+l)/2], v[r-1]);
    
    if(v[r-1]<v[l]) exch(v[l],v[r-1]);
    if(v[r]<v[l]) exch(v[l], v[r]);
    if(v[r]<v[r-1]) exch(v[r-1], v[r]);

    /*
    if(v[meio]<v[l]) exch(v[meio],v[l]);
    if(v[r]<v[l]) exch(v[r],v[l]);
    if(v[meio]<v[r]) exch(v[meio], v[r]);
    */


    int p = quick(v,l+1,r-1);
    quickSort(v, l,p-1);
    quickSort(v,p+1,r);

}

int main(){
        int v[5]={12,11,10,9,8};
        bubbleSort(v,0,5-1);

        for(int i = 0; i < 5; i++){
        printf("%d\n", v[i]);
        }

        return 0;
}
