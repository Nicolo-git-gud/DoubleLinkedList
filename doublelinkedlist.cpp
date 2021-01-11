
#include "doublelinkedlist.h"
#include <iostream>
#include <string>


DoubleLinkedList *DoubleLinkedList_new() {
    DoubleLinkedList *l = new DoubleLinkedList;
    l->head = nullptr;
    l->tail = nullptr;
    l->lenght = 0;
    return l;
}
int DoubleLinkedList_lenght(DoubleLinkedList *l){
    return l->lenght;
}
void DoubleLinkedList_delete(DoubleLinkedList *l){
    while(l->head!=nullptr){
        Cell *temp = l->head;
        l->head = l->head->next;
        delete temp;
    }
    delete l;
}
void DoubleLinkedList_pushback(DoubleLinkedList *l, int x){
    
    if(l->head==nullptr){
        Cell *primo = new Cell;
        primo->value = x;
        primo->next = nullptr;
        primo->prev = nullptr;
        l->head = primo;
        l->lenght = 1;
        l->tail = primo;
        
        return;
    }
    Cell *cur = new Cell;
    cur->value = x;
    cur->next = nullptr;
    cur->prev = l->tail;
    l->tail->next = cur;
    l->tail = cur;
    l->lenght++;
    
    
}

void DoubleLinkedList_pushfront(DoubleLinkedList *l,int v){
    Cell *aux = new Cell;
    aux->value = v;
    aux->next = l->head;
    aux->prev = nullptr;
    if(l->head != nullptr)//Altro, si ho fatto dopo questo che il pop, tapullo 
    l->head->prev = aux;
    l->head = aux;
    l->lenght ++;
}
int DoubleLinkedList_popback(DoubleLinkedList *l){
  if(l->head==nullptr){
        std::string err = "lista vuota";
        throw err;
    }
    
    if(l->lenght==1){
        int value = l->head->value;
        Cell *unico = l->head;
        l->head = nullptr;
        l->tail = nullptr;
        delete unico;
        l->lenght--;
        return value;
    }
    Cell *cur = l->tail;
    int value = cur -> value;
    l->tail = l->tail->prev;
    l->tail-> next = nullptr;
    delete cur;
    l->lenght--;
    return value;
}
int DoubleLinkedList_popfront(DoubleLinkedList *l){
    if(l->head==nullptr){
        std::string err = "lista vuota";
        throw err;
    }

    Cell *cur = l->head;
    int value = cur -> value;
    l->head = l->head->next;
    if(l->head != nullptr)//Questo mi sembra un tapullo ma non saprei come fare sennò a non causare una write su nullptr, e mi sembra forse meglio che scrivere un if l->lenght == 1
    l->head->prev = nullptr;
    delete cur;
    l->lenght--;
    return value;
}

void DoubleLinkedList_print(DoubleLinkedList *l){
    Cell *aux = l->head;
    while(aux != nullptr){
        std::cout << aux->value << std::endl;
        aux = aux->next;
    }
}
void DoubleLinkedList_print_reverse(DoubleLinkedList *l){
    Cell *rev = l->tail;
    while(rev != nullptr){
        std::cout << rev->value << std::endl;
        rev = rev->prev;
    }
}

DoubleLinkedList *DoubleLinkedList_Merge(DoubleLinkedList *A, DoubleLinkedList *B){
    DoubleLinkedList *Mergiato= DoubleLinkedList_new();
    if(A->head==nullptr && B->head==nullptr)
        return Mergiato;
    if(A->head==nullptr)
    {
        Cell *merge = B->head;
        Cell *current = new Cell;
        current->value = merge->value;
        current->next = nullptr;
        current->prev = nullptr;
        merge = merge->next;
        Mergiato->head = current;
        while(merge!=nullptr){
            Cell *aux = new Cell;
            aux->value = merge->value;
            aux->next = nullptr;
            aux->prev = current;
            merge = merge->next;
            current->next = aux;
            current = aux;
        }
        Mergiato->lenght = B->lenght;
        Mergiato->tail = current;
        return Mergiato;
        
    }
    else{
        Cell *merge=A->head;
        Cell *current = new Cell;
        current->value = merge->value;
        current->next = nullptr;
        current->prev = nullptr;
        merge = merge->next;
        Mergiato->head = current;
        while(merge!=nullptr){
            Cell *aux = new Cell;
            aux->value = merge->value;
            aux->next = nullptr;
            aux->prev = current;
            merge = merge->next;
            current->next = aux;
            current = aux;
        }
        if(B->head==nullptr){
            Mergiato -> lenght = A->lenght; 
            Mergiato->tail = current;
        return Mergiato;
        }
        merge=B->head;
        while(current->next!=nullptr)
            current = current->next;
        current->next=B->head;
        while(merge!=nullptr){
            Cell *aux = new Cell;
            aux->value = merge->value;
            aux->next=nullptr;
            aux->prev = current;
            merge = merge->next;
            current->next = aux;
            current = aux;
        }
    
    Mergiato->lenght = A->lenght + B->lenght;
    Mergiato->tail = current;
    return Mergiato;
    }
}

DoubleLinkedList *DoubleLinkedList_Merge_With_Copy(DoubleLinkedList *A, DoubleLinkedList *B){
  if(A->head == nullptr)
      return DoubleLinkedList_copy(B);
  if(B->head == nullptr)
      return DoubleLinkedList_copy(A);
    DoubleLinkedList *Merge = DoubleLinkedList_copy(A);
    DoubleLinkedList *copia2 = DoubleLinkedList_copy(B);
    Merge->tail->next = copia2->head;
    copia2->head->prev = Merge->tail;
    Merge->tail = copia2->tail;
    delete copia2;
    return Merge;
}

DoubleLinkedList * DoubleLinkedList_from_array(int a[], int c){
    DoubleLinkedList *l= DoubleLinkedList_new();
    if (c==0)
        return l;
    Cell *Cur = new Cell;
    Cur->value = a[0];
    Cur-> next = nullptr;
    Cur->prev = nullptr;
    l -> head = Cur;
    for (int i=1; i < c; i++){
        Cell *aux  =  new Cell;
        aux->value = a[i];
        aux->next = nullptr;
        aux->prev = Cur;
        Cur -> next = aux;
        Cur = aux;
        l->tail = aux;
    }
    l -> lenght = c;

    return l;
}


int * array_from_list(DoubleLinkedList *l){
   if(l->head==nullptr){
       int *b=new int[0];
       return b;
   }
    int n = l-> lenght;
    int *b = new int[n];
    Cell *cur = l-> head;
    for(int i=0;i<n;i++){
        b[i] = cur-> value;
        cur = cur->next;
    }
    return b;
}

DoubleLinkedList *DoubleLinkedList_copy (DoubleLinkedList *l){
    if (l->head==nullptr){
        return DoubleLinkedList_new();
    }
    DoubleLinkedList *b = DoubleLinkedList_new();
    Cell *copia = l->head;
    Cell *current = new Cell;
    current->prev = nullptr;
    current->value = l->head->value;
    current->next = nullptr;
    b->head = current;
    copia = copia->next;
    while(copia != nullptr){
        
        Cell *Aux = new Cell;
        Aux->value = copia->value;
        Aux->next = nullptr;
        Aux->prev = current;
        current->next = Aux;
        current = Aux;
        copia = copia->next;
    }
    b->lenght = l->lenght;
    b->tail = current;
    return b;
}
