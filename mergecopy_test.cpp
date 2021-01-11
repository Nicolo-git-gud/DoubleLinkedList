#include "doublelinkedlist.h"
#include <iostream>
#include <string>
#include <assert.h>
int main(){
    DoubleLinkedList *q = DoubleLinkedList_new();
    DoubleLinkedList *f = DoubleLinkedList_new();
    assert(q->head == q->tail);
    DoubleLinkedList_pushback(q,5);
    DoubleLinkedList_pushback(q,6);
    DoubleLinkedList_pushback(q,7);
    std::cout << "Eseguo la stampa normale" << std::endl;
    DoubleLinkedList_print(q);
    DoubleLinkedList *p = DoubleLinkedList_new();
    DoubleLinkedList_pushback(p,8);
    DoubleLinkedList_pushback(p,9);
    DoubleLinkedList_pushback(p,10);
    std::cout << "Provo la print per il merge" << std::endl;
    DoubleLinkedList *merge = DoubleLinkedList_Merge_With_Copy(q,p);//HO fatto tutte le prove q,f f,q e q e p(merge completo),p e q(merge completo ma invertito) ma per velocità ho cambiato solo dentro la parentesi;
    
    
    
    
    DoubleLinkedList_delete(q);
    
    DoubleLinkedList_delete(f);
    DoubleLinkedList_delete(p);
    DoubleLinkedList_print(merge);
    std::cout << "Provo la reverse print per il merge" << std::endl;
    DoubleLinkedList_print_reverse(merge);
    
    DoubleLinkedList_delete(merge);
    
}
