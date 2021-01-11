#include <assert.h>
#include "doublelinkedlist.h"
#include <iostream>
#include <string>

int main(){
    DoubleLinkedList *q = DoubleLinkedList_new();
    assert(q->head == q->tail);
    DoubleLinkedList_pushback(q,5);
    DoubleLinkedList_pushback(q,6);
    DoubleLinkedList_pushback(q,7);
    DoubleLinkedList_pushback(q,8);
    DoubleLinkedList_pushfront(q,1);
    
    int i = DoubleLinkedList_popback(q);
    std::cout << i << std::endl;
    i = DoubleLinkedList_popfront(q);
    std::cout << i << std::endl;
    i = DoubleLinkedList_popback(q);
    std::cout << i << std::endl;
     i = DoubleLinkedList_popfront(q);
    std::cout << i << std::endl;
     i = DoubleLinkedList_popfront(q);
     std::cout << i << std::endl;
         DoubleLinkedList_popfront(q);
    DoubleLinkedList_delete(q);
}
