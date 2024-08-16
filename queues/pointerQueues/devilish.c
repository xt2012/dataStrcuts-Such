
/*

    part of my studies on data structures & algorithms
    august 2024
    hOB.

*/

/* IMPLEMENT LIMITS FOR A CIRCULAR QUEUE AT SOME POINT  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct data{
    
    struct data*  next;
    struct data*  prev;
    char *characters;

}data;

typedef struct queue{

    data* head;
    data* tail;

    int size;

}queue;


int Push(queue* queue, char* characters){

    data* newData = malloc(sizeof(data));
                    if(!newData){ return -1; }

    size_t charactersLength = strlen(characters) + 1;
    newData->characters = strcpy(malloc(charactersLength * sizeof(char)), characters);
                if(!newData->characters){ return -1; }

    if ( queue->size==0 ){ 
        newData->next = NULL;
        newData->prev = NULL;
        queue->head = newData;
        queue->tail = newData;
        queue->size++;
    }else {//size>0 

        newData->prev = queue->head;
        
        //go back one & assign next to be this one
        queue->head->next = newData; 

        queue->head = newData;
        queue->size++;
    }

    return 0;
}

int Pop(queue* queue){
    
    data* freeData = queue->tail;

    queue->tail = queue->tail->next;

    queue->tail->prev = NULL;
    queue->size--;

    free(freeData->characters);
    freeData->next=NULL;
    freeData->prev=NULL;
    free(freeData);
    freeData = NULL;
    
    return 0;
}


int init_queue(queue** queue){

   (*queue)=malloc(sizeof(queue));
            if(!*queue){ return -1; }
   (*queue)->head=NULL;
   (*queue)->tail=NULL;
   (*queue)->size=0;


}

void Peek(queue* queue){
    data* tempData = queue->tail;


    for(int i = 0; i<queue->size; i++){
            printf("%s\n", tempData->characters);
            tempData=tempData->next;
    }

}

int Clear(queue* queue){

    for(int i = queue->size-1; i>=0; i--){
       if( i>0 ){

            queue->head = queue->head->prev;
            
            free(queue->head->next->characters);
            queue->head->next->next = NULL;
            queue->head->next->prev = NULL;
            free(queue->head->next);
            queue->size--;
       }else{
           
            free(queue->head->characters);
            queue->head->next = NULL;
            queue->head->prev = NULL;
            free(queue->head);
            queue->size--; 
       }
    }
    
    return 0;
}

int freeQueue(queue** queue){
    
    Clear((*queue));
    free((*queue));
    (*queue)=NULL;
    return 0;
}



int main(){
//  queue* queue = malloc(sizeof(queue));
    queue* queue = NULL;
    init_queue(&queue);

    Push(queue, "ksja");
    Push(queue, "second");
    Push(queue, "third");
    Push(queue, "fourth");
    Pop(queue);
//    Clear(queue);

    freeQueue(&queue);

     /*
     printf("%s", queue->head->characters);  
     Peek(queue); 
     SEGFAULTS just as intended 
     */

     printf("%p", queue);



    return 0;
}

