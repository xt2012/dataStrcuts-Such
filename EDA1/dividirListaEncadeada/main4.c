void divide_lista (celula *l, celula *l1, celula *l2){
    celula *temp = l->prox;
    celula *l1_tail = l1;
    celula *l2_tail = l2;

    while (temp!=NULL){
        if(temp->dado % 2 == 0){ 
            l1_tail->prox = temp;
            l1_tail=l1_tail->prox;
        }else{
            l2_tail->prox = temp;
            l2_tail=l2_tail->prox;
        }
        temp=temp->prox;
    }
    l1_tail->prox=NULL;
    l2_tail->prox=NULL;
    
}

