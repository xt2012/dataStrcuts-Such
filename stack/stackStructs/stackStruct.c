#include <stdio.h>
#include <stdlib.h>

struct dataStruct{
    char charStruct;
    struct dataStruct* prev;
    //could possibly have a next here too, do it later and adapt push instr.
};

/*
struct stackList{
    struct dataStruct* inicio;
    int tamanho;
};seen it done this way before, not sure if i like it enough to
replace my own almost list-like stack XD.
*/

int Push ( struct dataStruct** data, int* top, char c){
    //no dataStruct elements (none)
    if(*top==0){
        //top 0 here
       data[0] = malloc(sizeof(struct dataStruct));
                if(!*data){ return -1;  }

       data[0]->charStruct=c;
       data[0]->prev=NULL;
       (*top)++;
        return 0;
    }

            *data = realloc(*data, (sizeof(struct dataStruct) * ((*top)+1)) ); /* (*top)+1 given top hasnt been incremented, so "make space for that extra
            struct thats going to be place in a while. */
                                          if(!*data){  return -1; }
        
            (*data)[*top].charStruct = c;
 //           (*data)[*top].prev = data[*top - 1];
        
            //go through all prevs fixing addresses given inconstance
            //of address page frame offset on pointer returned by realloc
            for( int i = 1; i <= *top ; i ++ ){
                (*data)[i].prev = &(*data)[i-1]; 
            }

            (*top)++;
            return 0;
            
        

   return 0; 
}


struct dataStruct* Peek( struct dataStruct** data, int index, int* top ){

    return (index <= (*top) && index > -1) ? &(*data)[index] : NULL; 

}

int Pop( struct dataStruct** data, int* top){//LIFO, pop last(in first first out) & adjust top = top-1

//    (*data)[*top-1].charStruct=' ';
//    (*data)[*top-1].prev = NULL;
    (data)[*top-1]=NULL;  
//    free((data)[*top-1]);
    (*top)--;
    return 0;
}

struct dataStruct** List ( struct dataStruct** data ){

    return data;

}
void Clear ( struct dataStruct** data , int* top){

    *data=NULL;
    *top=0;
}

int main(){
    struct dataStruct* data = NULL;//pass the address of this to other functions
    int top = 0;
    //push
    //size
    //peek

    Push(&data, &top, 'j');
    Push(&data, &top, 'g');
    Push(&data, &top, 'k');
    Push(&data, &top, 'l');
//    Pop(&data, &top);
//      Clear(&data, &top);

//    printf("%d\n", top);
//    printf("%d\n", top);
   
    struct dataStruct** temp = (data!= NULL) ? List(&data) : NULL ; 
   

/*
   if(data != NULL){ 

        printf("%c, Prev: %p (address contains %c)\n", Peek(&data, 1, &top)->charStruct, Peek(&data, 1, &top)->prev, Peek(&data, 1, &top)->prev->charStruct );
     
    }else{
        
        printf("Data is NULL. Allocate it, fill it, & try again"); //peek working fine

    }
*/
  for (int i = 0; i < top; i++) {
      if(data!=NULL){
        printf("Element %d: %c, Prev: %c Prev Address: %p\n", i, data[i].charStruct, data[i].prev != NULL ? data[i].prev->charStruct : 'N', 
        data[i].prev != NULL ? data[i].prev : NULL);
             
      }
    }
   
    free(data);
    return 0;
}
