#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct dataStruct{

    char* characters;
    struct dataStruct* next;
}dataStruct;


typedef struct stack{ 

    struct dataStruct* top;
    int size;

}stack;

void init_stack_struct(struct stack** stack){
    (*stack)->top = NULL;
    (*stack)->size = 0;
}

int Push( struct stack* stack,char* characters){
    if (!stack) return -1; 
   
    dataStruct* newData = malloc(sizeof(dataStruct));
                if (!newData) return -1;  
    
    size_t len = strlen(characters)+1;

    newData->characters= strcpy(malloc(sizeof(char) * len), characters);

    if(!newData->characters) { free(newData); return -1; }

    strcpy(newData->characters, characters);
    newData->next = stack->top;
    stack->top = newData;
    stack->size++;
    
    return 0;        
}

int Pop(struct stack* stack){
    
    dataStruct* dataTransfer;

    dataTransfer = stack->top; 
    stack->top = stack->top->next;

    free(dataTransfer->characters);
    free(dataTransfer);

    stack->size--;
    return 0;
}

void List(stack* stack){
    
    dataStruct* temp = stack->top;

    for(int i = 0; i< stack->size ; i++){
        printf( "%s ; %p \n", temp->characters, temp->next);
        
        temp=temp->next;
    }

}

int populate_stack(stack* stack, char* input){

    size_t sizeInput = strlen(input)+1;
    char* Trueinput = strcpy( malloc(sizeInput * sizeof(char)), input );
    
    if(Push(stack, Trueinput) != 0){ 
        fprintf(stderr, "failed to push");
        return 1; 
    } 

    free(Trueinput);
    return 0;

}

int main(){
    stack* stack = malloc(sizeof(stack));
    if(!stack){ fprintf(stderr, "MEM. ALLOC. FAILED"); return 1; }
    
    init_stack_struct(&stack);//null all

   

    populate_stack(stack, "ABCDEFGOPSA");
    populate_stack(stack, "PQOWIAKSLQS");
    populate_stack(stack, "jajisdjaoisjdasij");

//    Pop(stack);
   
//    printf("%s ; size: %d\n", stack->top->characters, stack->size);

    List(stack);
    free(stack);
    return 0;
}
