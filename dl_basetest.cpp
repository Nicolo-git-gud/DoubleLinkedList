#include <assert.h>
#include "doublelinkedlist.h"
#include <iostream>
#include <string>

int main(){
    DoubleLinkedList *q = DoubleLinkedList_new();
    DoubleLinkedList *f = DoubleLinkedList_new();
    DoubleLinkedList_pushback(q,5);
    DoubleLinkedList_pushback(q,6);
    DoubleLinkedList_pushback(q,7);
    std::cout << "Eseguo la stampa normale" << std::endl;
    DoubleLinkedList_print(q);
    std::cout << "Eseguo la stampa reverse" << std::endl;
    DoubleLinkedList_print_reverse(q);
    DoubleLinkedList *p = DoubleLinkedList_new();
    DoubleLinkedList_pushback(p,8);
    DoubleLinkedList_pushback(p,9);
    DoubleLinkedList_pushback(p,10);
    std::cout << "Provo la print per il merge" << std::endl;
    DoubleLinkedList *merge = DoubleLinkedList_Merge(q,p);
    DoubleLinkedList *merge2 = DoubleLinkedList_Merge(q,f);
    DoubleLinkedList *merge3 = DoubleLinkedList_Merge(f,q);
    DoubleLinkedList_delete(f);
    DoubleLinkedList_delete(p);
    DoubleLinkedList_delete(q);
    DoubleLinkedList_print(merge);
    std::cout << "Provo la reverse print per il merge" << std::endl;
    DoubleLinkedList_print_reverse(merge);
    
    std::cout << "Provo la print per il merge2" << std::endl;
    DoubleLinkedList_print(merge2);
    std::cout << "Provo la reverse print per il merge2" << std::endl;
    DoubleLinkedList_print_reverse(merge2);
     
    std::cout << "Provo la print per il merge3" << std::endl;
    DoubleLinkedList_print(merge3);
    std::cout << "Provo la reverse print per il merge3" << std::endl;
    DoubleLinkedList_print_reverse(merge3);
    DoubleLinkedList_delete(merge);
    DoubleLinkedList_delete(merge2);
    DoubleLinkedList_delete(merge3);
}
