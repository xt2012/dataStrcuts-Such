/*
    data structures & algorithms
    dynamic nested list     
    august 17th 2024
    hOB.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


struct Node{
    struct Node* next;
    struct Node* prev;
    
    char* info; 
    size_t size;     
};

struct list{

    struct Node* start;
    struct Node* end;
    size_t size;


};

int initList( struct list* list ){
    
    list->start = NULL;
    list->end = NULL;
    list->size = 0;
    return 0;
}


struct Node** makeNodeList(struct list *list){
    struct Node** nodeList = malloc((list->size+1)*sizeof(struct Node*));
    

    struct Node* p = list->start;
        for(int i = 0; i<=list->size; i++){
        nodeList[i] = p;
        p=p->next;
    }
    return nodeList;
}


void nodeListToList(struct Node **nodeList, struct list *list){
    //update the next\prev pointers correctly
    if(list->size == 0) { return; }

    list->start = nodeList[0];
    list->end = nodeList[list->size];
    struct Node *p = list->start;
    p->prev = NULL;

    for(int i = 0; i<= list->size; i++){
        p->next = nodeList[i];
        nodeList[i]->prev=p;

        p=p->next;
    }

 }


void merge(struct list *list, struct Node **nodeList, size_t inicio, size_t centro, size_t fim){
    int fim1=0, fim2=0;
    int tamanho=fim-inicio+1;
    int p1=inicio;
    int p2=centro+1;
    int i,j,k;

    struct Node **temp = malloc(tamanho*sizeof(struct Node*));

    if(temp != NULL){
        for(i = 0; i<tamanho; i++){
            if(!fim1 && !fim2){//0 && 0, neither have been fully gone through.
                if( nodeList[p1]->size < nodeList[p2]->size ){
                    temp[i]=nodeList[p1];
                    temp[i]->size=nodeList[p1]->size;
                    temp[i]->info=nodeList[p1]->info;
                    ++p1;
                }else{
                    temp[i]=nodeList[p2];
                    temp[i]->info=nodeList[p2]->info;
                    temp[i]->size=nodeList[p2]->size;
                    ++p2;
                }

                if(p1>centro) fim1=1;
                if(p2>fim) fim2=1;
            }else{
                if(!fim1){//fim1 hasnt been fully gone thru thus fim2 has.
                    temp[i]=nodeList[p1];
                    temp[i]->info=nodeList[p1]->info;
                    temp[i]->size=nodeList[p1]->size;
                    p1++;
                }
                else{
                    temp[i]=nodeList[p2];
                    temp[i]->info=nodeList[p2]->info;
                    temp[i]->size=nodeList[p2]->size;
                    ++p2;
                }
            }
        }

        for(j = 0, k = inicio; j<tamanho; j++,k++){
            nodeList[k]=temp[j];
            nodeList[k]->info=temp[j]->info;
            nodeList[k]->size=temp[j]->size;
        }
        nodeListToList(nodeList,list);
    }

    free(temp);
    temp=NULL;
}


void mergeSort(struct list *list, struct Node** nodeList, size_t inicio, size_t fim){

    size_t centro;
    if(inicio < fim){
        centro = (inicio+fim)>>1;
        mergeSort(list, nodeList, inicio, centro);
        mergeSort(list, nodeList, centro+1, fim);
        merge(list, nodeList, inicio, centro, fim);
    }


}



void mergeSortReal(struct list *list, size_t inicio, size_t fim){
    struct Node **nodeList = makeNodeList(list);
    mergeSort(list, nodeList, 0, list->size);
    free(nodeList);
}


struct Node* bubbleSortLesserToGreater(struct list* list) {
   struct Node *p, *q;
   p=list->start;
   q=p->next;

   char* tempInfo;
   size_t tempSize;

   int continueFlag=0, i=0;
   size_t end = list->size;

    do{
       for(i=0; i<end; i++){
            if( q->size < p->size ){
                tempInfo = p->info;
                tempSize = p->size;
                
                p->info = q->info;
                p->size = q->size;

                q->info = tempInfo;
                q->size = tempSize;

                continueFlag = i;
                } 
                p=p->next;
                q=p->next;
            }

            p=list->start;
            q=p->next;
        
            end--;
       
       }while(continueFlag!=0);

    return list->start;
}

struct Node* bubbleTest(struct list* list){
    struct Node *p;
    p=list->start;
   
    size_t end = list->size;

    char* infoTemp;
    size_t sizeTemp;
    int counter;
    
    do{
        counter = 0;
        for(int i = 0; i<end; i++){
           
           if(p->size > p->next->size){
                infoTemp = p->next->info;
                sizeTemp = p->next->size;      
           
                p->next->size = p->size;
                p->next->info = p->info;
                p->size = sizeTemp;
                p->info = infoTemp;
                counter = i;
           }
           p=p->next;
       }
           p = list->start;
           end--;
    }while(counter != 0);

    return list->start;
}

struct Node* insertionSort (struct list* list){
    struct Node *p, *q;
    char* tempInfo;
    size_t tempSize;

    p = list->start->next;
    
    for(int i=1; i<list->size+1; i++ ){

       tempInfo = p->info;
       tempSize = p->size;
       q = p->prev;

           while(q != NULL && q->size > tempSize){
              q->next->size = q->size;
              q->next->info = q->info;
              q = q->prev;
           }

           if(q == NULL){
                list->start->info = tempInfo;
                list->start->size = tempSize;
           }else{
                q->next->info = tempInfo;
                q->next->size = tempSize;
           }
           p = p->next;
       } 
    return list->start;
}

struct Node* insertionTest(struct list* list){
    struct Node *p, *q;
    p=list->start->next;
    q=p->prev;

    char* tempInfo;
    size_t tempSize;

    for(int i = 1; i<list->size+1; i++){
        tempInfo = p->info;
        tempSize = p->size;
        q=p->prev;
        for(int j = i; (j>0)&& q!=NULL &&(q->size > tempSize); j-- ){
            q->next->info = q->info;
            q->next->size = q->size;
            q=q->prev;
        }
        if(q == NULL){
            list->start->info = tempInfo;
            list->start->size = tempSize;
        }else{
            list->start->next->info = tempInfo;
            list->start->next->size = tempSize;
            }

        p=p->next;
    }


    return list->start;
}

struct Node* selectionSort(struct list* list){

    struct Node *beginControl = list->start;

    //these two are just the I and J for the loops.
    struct Node *greaterI=beginControl;
    struct Node *greaterJ = greaterI->next;

    struct Node *menor=malloc(sizeof(struct Node));
    char* tempInfo;  tempInfo = NULL;
    size_t tempSize; tempSize=0;
     
    for( int i = 0; i<list->size-1; i++){
        menor=greaterI;
        menor->size=greaterI->size;
        menor->info=greaterI->info;       

        for(int j = i+1; j<list->size+1; j++){//check for lessers
            if(greaterJ->size < menor->size){
                    menor = greaterJ;
                    menor->size = greaterJ->size;
                    menor->info = greaterJ->info;
            }
            greaterJ=greaterJ->next;
        }
        

        if(menor != greaterI){
            tempSize = greaterI->size;
            tempInfo = greaterI->info;

            greaterI->size = menor->size;
            greaterI->info = menor->info;

            menor->size = tempSize;
            menor->info = tempInfo;
        }
       
       beginControl=beginControl->next;
       greaterI=beginControl;
       greaterJ=greaterI->next;
    }
    //free(menor); this wont work cause "menor" points to an already existing node. 
    //and given the freeing is already handled in a different function, doing it here
    //causes a double free in tcache 
    menor = NULL;
    return list->start;
}

int verAddress(void* address1, void* address2){

    if(address1 == address2){ return 0; } 
    else { return -1; }


}

int PushEnd( struct list* listInput, char* dataToBe ){
    struct Node* temp = malloc(sizeof(struct Node));
                        if(!temp) { return -1; } 

    size_t len_dataToBe = strlen(dataToBe);
    temp->info = strcpy( malloc( (len_dataToBe+1)* sizeof(char)), dataToBe );
                 if(!temp->info) { return -1; }
    temp->size = len_dataToBe;

    if (listInput->size == 0){ 
        
        listInput->start = temp;
        listInput->end = temp;
        listInput->size++;
        return 0; 
    }

    
    temp->prev = listInput->end;
    
    listInput->end = temp;
    listInput->size++;
    return 0;
}

int PushStart( struct list* listInput, char* dataToBe ){
    struct Node* temp = malloc(sizeof(struct Node));
                        if(!temp){ return -1; }
    
    size_t len_dataToBe=strlen(dataToBe);
    temp->info = strcpy(malloc((len_dataToBe + 1)*sizeof(char)), dataToBe );
                        if(!temp->info){ return -1; }
    temp->size = len_dataToBe;

    if(listInput->size==0) {
        listInput->start=temp;
        listInput->end=temp;
        listInput->size++;
        return 0;
    }
    
   listInput->start->prev = temp;
   temp->next=listInput->start;
   listInput->start = temp;
   return 0;
}

int PushAmong(struct list* listInput, char* dataToBe, char* toBeLooked){
    struct Node* forTemp = listInput->start; 

    struct Node* temp = malloc(sizeof(struct Node));
    size_t len_dataToBe = strlen(dataToBe);
    temp->size = len_dataToBe;
    temp->info = strcpy( malloc((len_dataToBe+1)*sizeof(char)), dataToBe );

    for(int i=0; i<listInput->size; i++){
        
        if( strcmp( toBeLooked, forTemp->info ) == 0 ){
            //printf("fent debug typa shi'\n");
            
            if(forTemp == listInput->end){
               
                temp->prev = listInput->end->prev;
                temp->next = listInput->end;

                listInput->end->prev->next = temp;
                listInput->end->prev = temp;
                 
                listInput->size++;
                return 0;
            }
            
            else{
                temp->prev = forTemp;
                temp->next = forTemp->next;
                forTemp->next->prev = temp;
                forTemp->next = temp;
                listInput->size++;            
                return 0;
            }
        }

        forTemp = forTemp->next;
    }

    return -1;
}

int cleanList(struct list* list){
//turn this shit into a talkative idiot with some crazy prints & such to indicate what is being
//cleared

    size_t temp = list->size;
    struct Node* tempPointer;

    for(int x = 0; x<temp; x++){
    
        list->start->size = 0;
        list->start->prev = NULL;
        
        free(list->start->info);
        list->start->info = NULL;

        tempPointer = list->start->next;
        list->start->next = NULL;
        free(list->start);

        list->start = tempPointer;
        list->size--;
    
    }


    //end here. No if : less complexity.
        list->end->size = 0;
        list->end->prev = NULL;
        free(list->end->info);
        list->end->info=NULL;
        
        free(list->end);
        list->start=NULL;
        list->end = NULL;
//        list->size--; no not needed.
        return 0;
}

struct Node** Peek(struct list* list){ 
/*just for the sake of a good time allocate it. keep in mind this is "complex" for no reason
besides just bloating the code(aka having fun)
could be done in a simpler way*/
                                //given size "begins" at 0 add one to normalize it so C 
                                //indexing standard.
    struct Node** arrayNodes = malloc( (list->size+1) * sizeof(struct Node*) );
                                if(!arrayNodes){ return NULL; }

    struct Node* temp = list->start;

    for (int x = 0 ;x<=list->size; x++){
      
          if(x==list->size){ arrayNodes[x] = list->end; return arrayNodes;}
    
      arrayNodes[x] = temp;
      temp = temp->next;

    }
    return arrayNodes;

}

//seek return mem address? //<------- 2nd

//peek - returns an array of type Node through a for loop

//remove<---------3rd
//sort (size of info ?)
//duplicate
//findDuplicates
//move

//clean function that null's the list, thus also make a function that creates a new list and
//add its address to some indexing array.

int main(int argc, char** argv){

    struct list* list1 = malloc(sizeof(struct list));
    initList(list1);
/*
    //PushEnd(list1, argv[1]);
    PushEnd(list1, "end");
    PushStart(list1, "start");

    PushAmong(list1, "afterStart", "start");
    PushAmong(list1, "beforeBeforeEnd", "afterStart");
    PushAmong(list1, "beforeEnd", "beforeBeforeEnd");
*/
    PushEnd(list1, "start");
    PushStart(list1, "endddddddddddddd");

    PushAmong(list1, "fourthhhhhhh", "endddddddddddddd");
    PushAmong(list1, "secondddd", "fourthhhhhhh");
    PushAmong(list1, "thirdddddd", "secondddd");
    PushAmong(list1, "fifthhhhhhhhhh", "secondddd" );
   

//bubbleSortLesserToGreater( list1 );
//insertionSort(list1);
//selectionSort(list1);

//bubbleTest(list1);
//insertionTest(list1);

/*
struct Node** nodeList = makeNodeList(list1);
mergeSort(list1, nodeList, 0, list1->size);
free(nodeList);*/

mergeSortReal(list1, 0, list1->size);

//struct Node** runThru = makeNodeList(list1);
//nodeListToList(runThru, list1);
/*
    printf("%s\n",list1->start->info);
    printf("%ld\n",list1->start->size);
    printf("%p\n\n", list1->start);

    //afterStart  
    printf("%s\n",list1->start->next->info);
    printf("%ld\n",list1->start->next->size);
    printf("beforeBeforeEnd: %p\n", list1->start->next->next);
    printf("beforeBeforeEnd: %p\n\n", list1->end->prev->prev);

    //beforeBeforeEnd
    printf("%s\n",list1->start->next->next->info);
    printf("%ld\n",list1->start->next->next->size);
    printf("beforeEnd: %p\n", list1->start->next->next->next);
    printf("beforeEnd: %p\n\n", list1->end->prev);


    //beforeEnd
    printf("%s\n",list1->start->next->next->next->info);
    printf("%ld\n",list1->start->next->next->next->size);
    printf("End: %p\n", list1->start->next->next->next->next);
    printf("End: %p\n", list1->end);
    
    printf("beforeEnd: %p\n",list1->start->next->next->next);
    printf("beforeEnd: %p\n\n",list1->end->prev);
//function for this shit up here maybe you bastard
        
//    printf("%s\n",list1->end->info);
//    printf("%ld\n",list1->end->size);
//    printf("%p\n\n",list1->end);
done made it fuck you*/
    
   
    struct Node*** peekList = malloc(sizeof(struct Node**));
    (*peekList) = Peek(list1);
    printf("size:%ld\n\n", (list1->size));

    //--------
    printf("element number %d\n", 0);
    printf("%s\n", (*(peekList))[0]->info);
    printf("string size: %ld\n",  (*   ( (*(peekList)) + 0) )->size );
    printf("next: %s\n\n", (*(peekList))[0]->next->info);
    
    for (size_t x = 1; x<=(list1->size)-1; x++ ){
        
        printf("element number %ld\n", x);
        printf("%s\n", (*(peekList))[x]->info);
        printf("string size: %ld\n",  (*   ( (*(peekList)) +x) )->size );
        printf("next: %s\n", (*(peekList))[x]->next->info);
        printf("prev: %s\n\n", (*(peekList))[x]->prev->info);

    /* imagine actually doing this. complexity maniacs simply ascend
    if(x == 0){
        printf("next: %s\n", (*(peekList))[x]->next->info);
    }else if(x == list1->size){
        printf("previous: %s\n", (*(peekList))[x]->prev->info);
    }else {
        printf("previous: %s\n", (*(peekList))[x]->prev->info);
        printf("next: %s\n", (*(peekList))[x]->next->info);
        }
    */

    }

    printf("element number %ld\n", list1->size);
    printf("%s\n", (*(peekList))[list1->size]->info);
    printf("string size: %ld\n",  (*   ( (*(peekList)) + list1->size) )->size );
    printf("prev: %s\n\n", (*(peekList))[list1->size]->prev->info);
 
    free(*(peekList)); 
    free(peekList);
    peekList = NULL;
    //--------
    





    cleanList(list1);
    printf("%ld\n",(list1->size));
    printf("end:  %p\n", list1->end);
    printf("start:%p\n", list1->start);
    free(list1);
    list1 = NULL; 
    return 0;

}
