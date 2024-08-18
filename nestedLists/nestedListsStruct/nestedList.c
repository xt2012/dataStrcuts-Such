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

int PushEnd( struct list* listInput, char* dataToBe ){
    struct Node* temp = malloc(sizeof(struct Node));
                        if(!temp) { return -1; } 

    size_t len_dataToBe = strlen(dataToBe);
    temp->info = strcpy( malloc( len_dataToBe * sizeof(char)), dataToBe );
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
    temp->info = strcpy(malloc(len_dataToBe*sizeof(char)), dataToBe );
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


}

//seek return mem address?
//peek
//remove
//sort (size of info ?)
//duplicate
//findDuplicates
//move


int main(int argc, char** argv){

    struct list* list1 = malloc(sizeof(struct list));
    
    //PushEnd(list1, argv[1]);
    PushEnd(list1, "end");
    PushStart(list1, "start");


    printf("%s\n",list1->start->info);
    printf("%ld\n",list1->start->size);
    printf("%p\n",list1->start->next);
    printf("%p\n",list1->start->prev);
    printf("%p\n",list1->end);

    printf("%s\n",list1->end->info);
    printf("%ld\n",list1->end->size);
    printf("%p\n",list1->end->next);
    printf("%p\n",list1->end->prev);
    printf("%p\n",list1->start);




    return 0;

}
