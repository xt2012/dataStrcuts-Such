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

int bubbleSortLesserToGreater1( struct list* list ){//sort by size
      struct Node *i, *j; 
      struct Node* head = list->start;
      int num;

      for(i = head; i->next != NULL; i=i->next){
        for(j=i->next; j!=NULL;j=j->next){
           if(i->size > j->size){
                num=j->size;
                j->size = i->size;
                i->size = num;
           }
        }
      }
    
    return 0;
}

struct Node* bubbleSortLesserToGreater(struct Node* start) {
    struct Node *end = NULL, *p, *q;

    if (start == NULL || start->next == NULL) {
        return start;
    }

    while (end != start->next) {
        p = start;
        while (p->next != end) {
            q = p->next;
            if (p->size > q->size) {
                // Swap sizes
                size_t tempSize = p->size;
                p->size = q->size;
                q->size = tempSize;

                // Swap info pointers
                char* tempInfo = p->info;
                p->info = q->info;
                q->info = tempInfo;
            }
            p = p->next;
        }
        end = p;
    }

    return start;
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
    PushStart(list1, "enddddddddddd");

    PushAmong(list1, "fourthhhhhhh", "enddddddddddd");
    PushAmong(list1, "secondddd", "fourthhhhhhh");
    PushAmong(list1, "thirdddddd", "secondddd");

   

    bubbleSortLesserToGreater( list1->start );

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
