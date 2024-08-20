/*
    data structures & algorithms
    dynamic nested list     
    august 17th 2024
    hOB.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int verAddress(void * address1, void * address2){

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
            printf("fent debug typa shi'\n");
            
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


    /*  list->end->prev = NULL;
        list->end = NULL;
        list->start->size = 0;
        list->start->prev = NULL;
        free(list->start->info);
        list->start->info=NULL;
        list->start->next=NULL;
        
        free(list->start);
        list->start=NULL;
        list->size--;   
     */

    //end here. No if : less complexity.
        list->end->size = 0;
        list->end->prev = NULL;
        free(list->end->info);
        list->end->info=NULL;
        
        free(list->end);
        list->start=NULL;
        list->end = NULL;
        list->size--;
        return 0;
}


//seek return mem address?
//peek
//remove
//sort (size of info ?)
//duplicate
//findDuplicates
//move
//clean function that null's the list, thus also make a function that creates a new list and
//add its address to some indexing array.

int main(int argc, char** argv){

    struct list* list1 = malloc(sizeof(struct list));
    initList(list1);
    //PushEnd(list1, argv[1]);
    PushEnd(list1, "end");
    PushStart(list1, "start");

    PushAmong(list1, "afterStart", "start");
    PushAmong(list1, "beforeBeforeEnd", "afterStart");
    PushAmong(list1, "beforeEnd", "beforeBeforeEnd");

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


    printf("%s\n",list1->end->info);
    printf("%ld\n",list1->end->size);
    printf("%p\n\n",list1->end);





// /*
    cleanList(list1);
    
    printf("%ld\n",list1->size);

    printf("end:  %p\n", list1->end);
    printf("start:%p\n", list1->start);

    free(list1);
// */ 
    return 0;

}
