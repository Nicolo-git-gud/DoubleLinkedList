#include "assert.h"
#include "doublelinkedlist.h"
#include <iostream>
#include <string>

int main()
{
    DoubleLinkedList *q = DoubleLinkedList_new();
    inserimento_ordine(q, 5);
    assert(q->tail->value == 5);
    std::cout << "Provo l'order insert con un solo elemento e la stampa" << std::endl;
    DoubleLinkedList_print(q);
    inserimento_ordine(q, 6);
    assert(q->tail->value == 6);
    std::cout << "Provo l'order insert con due elementi e la stampa" << std::endl;
    DoubleLinkedList_print(q);
    inserimento_ordine(q, 7);
    assert(q->tail->value == 7);
    inserimento_ordine(q, 8);
    assert(q->tail->value == 8);
    inserimento_ordine(q, 8);
    inserimento_ordine(q, 4);
    assert(q->tail->value == 8);
    inserimento_ordine(q, 6);
    inserimento_ordine(q, 5);
    assert(q->tail->value == 8);
    assert(q->tail->value == 8);

    inserimento_ordine(q, 10);
    assert(q->tail->value == 10);
    inserimento_ordine(q, 2);
    assert(q->tail->value == 10);
    inserimento_ordine(q, 7);
    assert(q->tail->value == 10);
    std::cout << "Provo l'order insert con più elementi e la stampa" << std::endl;
    DoubleLinkedList_print(q);
    int l = DoubleLinkedList_lenght(q);
    std::cout << "La lunghezza è " << l << std::endl;
    std::cout << "Provo la print reverse che utilizza prev " << std::endl;
    DoubleLinkedList_print_reverse(q);
    DoubleLinkedList_delete(q);
}
