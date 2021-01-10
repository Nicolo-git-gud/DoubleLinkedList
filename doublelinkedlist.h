#ifndef doublelinkedlist_h
#define doublelinkedlist_h

struct Cell {
    int value;
    Cell *next;
    Cell *prev;
};

struct DoubleLinkedList {
    Cell *head;
    int lenght;
    Cell *tail;
 
};

DoubleLinkedList *DoubleLinkedList_new();
int DoubleLinkedList_lenght(DoubleLinkedList *l);
void DoubleLinkedList_delete(DoubleLinkedList *l);
void DoubleLinkedList_print(DoubleLinkedList * l);
void DoubleLinkedList_pushback(DoubleLinkedList *l, int x);
int DoubleLinkedList_popback(DoubleLinkedList *l);
void DoubleLinkedList_pushfront(DoubleLinkedList *l,int v);
int DoubleLinkedList_popfront(DoubleLinkedList *l);
DoubleLinkedList *DoubleLinkedList_Merge(DoubleLinkedList *A, DoubleLinkedList *B);
DoubleLinkedList *DoubleLinkedList_copy (DoubleLinkedList *l);
void reverse_print_cell(Cell *c);
void rec_print_cell(Cell *c);
void DoubleLinkedList_reverse_print(DoubleLinkedList *l);
void DoubleLinkedList_recoursive_print(DoubleLinkedList *l);
void DoubleLinkedList_print_reverse(DoubleLinkedList *l);
DoubleLinkedList *DoubleLinkedList_Merge(DoubleLinkedList *A, DoubleLinkedList *B);
DoubleLinkedList * DoubleLinkedList_from_array(int a[], int c);




#endif 
