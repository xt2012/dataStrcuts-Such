#define exch(A, B) do { int temp = (A); (A) = (B); (B) = temp; } while (0)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int (*Compare)(const void *, const void *);

struct data{
    int datA;
    struct data *next; 
    struct data *prev;
};

struct head{
    struct data *start;
    struct data *end;
    int size;
};


struct head *initData (int k){
    struct data *data = malloc(sizeof(struct data));
    struct head *head = malloc(sizeof(struct head));

    data->datA = k;
    data->next = NULL;
    data->prev = NULL;
    
    head->start = data;
    head->end = data;
    head->size++;

    return head;

}

int comp(const void* v1, const void* v2){
    const struct data *data1 = v1;
    const struct data *data2 = v2;

    if(data1->datA > data2->datA){
        return 1;
    }else if(data1->datA == data2->datA){
        return 0;
    }else{
        return -1;
    }
}

void addNext( struct head *head, int k ){
    struct data *tempData = head->start;
    for(int i = 0; i<head->size-1; i++){
        tempData=tempData->next;
    }
    
    struct data *newData = malloc(sizeof(struct data));
    newData->datA = k;
    newData->prev = tempData;

    tempData->next = newData;
    newData->next=NULL;


    head->end = newData;
    head->size++;
}



void selectionSort( int *v, int l, int r ){
    int menor;

    for( int i=l; i<r; i++ ){
        menor = i;
        for( int j=i+1; j<=r; j++ ){
            if( v[j] < v[menor] ){
                menor = j;
            }
        }
        
        if( menor != i ){
            exch(v[i], v[menor]);
        }

    }


}

void selectionSortList( struct head *head, Compare comp){
    struct data *tempi = head->start;
    struct data *tempj;
    struct data *menor;
    while( tempi != NULL ){
        menor = tempi;
        tempj = tempi->next;

            while(tempj != NULL){
                if(comp(tempj,menor) < 0){
                    menor = tempj;
                }
                tempj=tempj->next;
            }
        if(menor != tempi){
            exch(tempi->datA, menor->datA);
        }

        tempi=tempi->next;
    }

}       

void nonOpt_bubbleSort( int *v, int l, int r, Compare compare ){
    while(l < r){
        for(int j = l; j<r && comp(&v[j],&v[j+1])>0; j++){
            exch(v[j], v[j+1]);
        }
        r--;
    }

}

void nonOpt_bubbleSortList( struct head *head, int l, int r, Compare comp ){
    struct data *tempj = NULL;

    while(l < r){
        tempj = head->start;

        while(tempj != NULL && tempj->next != NULL){
                if(comp(tempj, tempj->next) > 0){
                    exch(tempj->datA, tempj->next->datA);
                }
                tempj=tempj->next;
        }
        r--;
    }

}


void opt_bubbleSort( int *v, int l, int r, Compare compare ){
    int swap = 1;
    while(l < r && swap){
        swap = 0;
        for(int j = l; j<r && comp(&v[j],&v[j+1])>0; j++){
            swap = 1;
            exch(v[j], v[j+1]);
        }
        r--;
    }

}


void optDrag_bubbleSort( int *v, int l, int r, Compare compare ){
    int swap = 1;
    int temp = 0;
    int j = l;
    while(l < r && swap){
        j=l;
        swap = 0;
        temp = v[j];
        for(j = l; j<r && comp(&v[j+1],&temp)<0; j++){
            v[j] = v[j+1];
            swap=1;
        }
        v[j]=temp;
        r--;
    }

}

void opt_bubbleSortList( struct head *head, int l, int r, Compare comp ){
    struct data *tempj = NULL;
    int swap = 1;

    while(l < r && swap){
        tempj = head->start;
        swap = 0;

        while(tempj != NULL && tempj->next != NULL){
                if(comp(tempj, tempj->next) > 0){
                    exch(tempj->datA, tempj->next->datA);
                    swap = 1;
                }
                tempj=tempj->next;
        }
        r--;
    }

}

void insertionSort( int *v, int l, int r, Compare compare ){
    for(int i = l+1; i<r; i++){
        for(int j = i; j>l; j--){
            if(comp(&v[j], &v[j-1])< 0){
                exch(v[j], v[j-1]);
            }
        }
    }

}

void drag_insertionSort( int *v, int l, int r, Compare compare ){
    int temp,i,j;
    for(i = l+1; i<=r; i++){
        temp = v[i];
        for(j = i; j>l; j--){
            if(comp(&v[j-1], &temp) > 0){
                v[j]=v[j-1];
            }
        }
        v[j]=temp;
    }
}

void insertionSortList( struct head *head, int l, int r, Compare compare ){
    struct data *tempi = head->start; 
    struct data *tempj = tempi;

    while(tempi){
        tempj=tempi;
        while(tempj && tempj->prev){
            if(comp(tempj, tempj->prev)<0){
                exch(tempj->datA, tempj->prev->datA);
            }
            tempj=tempj->prev;
        }
        tempi=tempi->next;
    }
}

/*
 233     struct data *tempi = head->start->next;
 234     struct data *tempj = tempi;
 235     int elem;
 236
 237     while(tempi){
 238         elem = tempi->datA;
 239         tempj=tempi;
 240         while(tempj && tempj->prev){
 241             if(comp(&elem,&tempj->prev->datA)<0){
 242                 tempj->datA=tempj->prev->datA;
 243             }
 244
 245             tempj=tempj->prev;
 246         }
 247         tempj->datA = elem;
 248         tempi=tempi->next;
 249     }
 250 }
*/
void drag_insertionSortList( struct head *head, int l, int r, Compare compare ){
    struct data *tempi = head->start->next; 
    struct data *tempj = tempi;
    int elem;

    while(tempi){
        elem = tempi->datA;
        tempj=tempi;
        while(tempj->prev && 
            comp(&elem,&tempj->prev->datA)<0
            ){
                tempj->datA=tempj->prev->datA;
                tempj=tempj->prev;
             }
        tempj->datA = elem;
        tempi=tempi->next;
    }
}

void shellSort( int *v, int l, int r, Compare comp ){
    int h = 1;
    
    while(h < (r-l+1)/3)
        h=3*h+1;

    while(h>=1) {
        for(int i = l+h; i <= r; i++){
            for(int j = i; j>=l+h && v[j]<v[j-h]; j-=h){
                exch(v[j],v[j-h]);
            }
        }
        h/=3;
    }
        
}

void shellSortList( struct head *head, int l, int r, Compare comp ){

    struct data *dataList[head->size];
    struct data *temp = head->start;
    for(int i = 0; i < head->size; i++){
        dataList[i] = temp;
        temp = temp->next;
    }//data list list.

    /*
    for(int i = 0; i < head->size; i++){
        printf("%d\n", dataList[i]->datA);
    }*/

    int h = 1;
    while(h < (r-l+1)/3)
        h=h*3+1;

    while(h>=1){
        for(int i=h;i<r;i++){
            for(int j=i; j>=l+h && 
               dataList[j]->datA<dataList[j-h]->datA;

               j-=h){
                exch(
                    dataList[j]->datA, 
                    dataList[j-h]->datA
                    );
            }
        }
        h=h/3;
    }


}

void merge(int *v, int l, int m, int r){
    int size = r-l+1;
    int *temp = malloc(sizeof(int) * size);

    int i, j, k;
    i=l; j=m+1; k=0;
    
    while(i<=m && j<=r){
        if(v[i] <= v[j]){
            temp[k++]=v[i++];
        }else{
            temp[k++]=v[j++];
        }
    }

    while(i<=m) temp[k++]=v[i++];
    while(j<=r) temp[k++]=v[j++];

    for(i=l,k=0; i<=r; i++,k++){
        v[i]=temp[k];
    }
    free(temp);
    temp=NULL;
}

void mergeSort( int *v, int l, int r) {
    if(l>=r) return;

    int m = (r+l)/2;

    mergeSort(v, l, m);
    mergeSort(v, m+1, r);
    merge(v, l, m, r);
}

int quick(int *v, int l, int r){
    int pivot=v[r];
    int i, j;
    i=l-1;
    j=r;
    

    while( i<j ){
        while( v[++i]< pivot );

        while( v[--j]> pivot && j>l);

        if(i<j) exch(v[i],v[j]);
    }

    exch(v[i],v[r]);

    return i;
}

void basicQuickSort( int *v, int l, int r ){
    if( r <= l ) return;
  

    int pivot = quick( v, l, r );
    basicQuickSort(v, l, pivot-1);
    basicQuickSort(v, pivot+1, r);
}

void medianaQuickSort( int *v, int l, int r ){
    if( r <= l ) return;
    
    int meio = (r+l)/2;
    if(v[meio]<v[l]) exch(v[meio], v[l]);
    if(v[r]<v[l]) exch(v[r],v[l]);
    if(v[meio]<v[r]) exch(v[meio], v[r]);
    

    int pivot = quick( v, l, r );
    medianaQuickSort(v, l, pivot-1);
    medianaQuickSort(v, pivot+1, r);
}


void medianaOtQuickSort( int *v, int l, int r, Compare comp ){
    //if( r <= l ) return;
    if(r-l<=15) return insertionSort(v,l,r, comp);
    
    int meio = (r+l)/2;
    exch(v[meio], v[r-1]);
    if(comp(&v[l], &v[r-1])<0) exch(v[l], v[r-1]);
    if(comp(&v[l],&v[r])<0) exch(v[l],v[r]);
    if(comp(&v[r-1],&v[r])<0) exch(v[r-1], v[r]);
    

    int pivot = quick( v, l+1, r-1 );
    medianaOtQuickSort(v, l, pivot-1, comp);
    medianaOtQuickSort(v, pivot+1, r, comp);
}
int main(int argc, char** argv){
      int n;
    scanf("%d", &n);
    printf("%d elementos\n", n);
    int *v = malloc(n*sizeof(int));
     for(int i=0; i<n; i++) scanf("%d", &v[i]);


    if( strcmp(argv[1], "lista")==0 ){
        struct head *head1 = initData(50);   
        addNext( head1, 123 );
        addNext( head1, 1 );
        addNext( head1, 5 );
        addNext( head1, 13 );
        addNext( head1, 148 );
        addNext( head1, 3 );
        addNext( head1, 2 );

        /*
        struct data *temp2 = head1->end;

        while(temp2){
            printf("%d\n", temp2->datA);
            temp2=temp2->prev;
        }*/


        struct data *tempData = head1->start;
        printf("Antes da ordenacao\n");
        for(int i = 0; i < head1->size; i++){
            printf("%d\n", tempData->datA);
            tempData=tempData->next;
        }
        printf("\n");
        //selectionSortList( head1, comp );
        //opt_bubbleSortList( head1,0,5-1, comp );
        //drag_insertionSortList(head1, 0, 5-1, comp);
        shellSortList(head1, 0, head1->size, comp);
        
        tempData = head1->start;
        printf("Depois da ordenacao\n");
        for(int i = 0; i < head1->size; i++){
            printf("%d\n", tempData->datA);
            tempData=tempData->next;
        }
        printf("\n");
    }else{
        int A[5] = {12, 10, 9, 7, 4};

        printf("Antes da ordenacao\n");
        for(int i=0; i<5; i++){
            printf("%d\n", A[i]);
        }
        //selectionSort(v, 0, n);
        //optDrag_bubbleSort(A,0,5, comp);
        // drag_insertionSort(A, 0, 5-1, comp);
        //mergeSort(A,0,5-1);
        //basicQuickSort(v, 0, n);
        medianaOtQuickSort(v, 0, n, comp);
        printf("\nDepois da ordenacao\n");
        for(int i=0; i<5; i++){
            printf("%d\n", A[i]);
        }
    }
    free(v);
}
