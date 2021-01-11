#include <assert.h>
#include "doublelinkedlist.h"
#include <iostream>
#include <string>

int main(){
    DoubleLinkedList *q = DoubleLinkedList_new();
    DoubleLinkedList_pushback(q,5);
    DoubleLinkedList_pushback(q,6);
    DoubleLinkedList_pushback(q,7);
    DoubleLinkedList *c = DoubleLinkedList_copy(q);
    DoubleLinkedList_delete(q);
    DoubleLinkedList_print_reverse(c);
    DoubleLinkedList_delete(c);
}
