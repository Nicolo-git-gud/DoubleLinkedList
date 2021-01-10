
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
    if(l->lenght==1)
        cur->prev = l->head;
    else
        cur->prev = l->tail;
    l->tail->next = cur;
    l->tail = cur;
    l->lenght++;
    
        
}

void  DoubleLinkedList_print(DoubleLinkedList *l){
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


