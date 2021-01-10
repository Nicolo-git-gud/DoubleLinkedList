#include<iostream>
#include <assert.h>
#include "doublelinkedlist.h"



int main(){
    
    int n = 5;    
    int a[n];
    for (int i=0;i<n;i++)
        a[i]=i;
    DoubleLinkedList *lst = DoubleLinkedList_from_array(a,n);
    int c = DoubleLinkedList_lenght(lst);
    std::cout << "La lunghezza è: "<< c << std::endl;
    std::cout << "Eseguo la print normale" << std::endl;
    DoubleLinkedList_print(lst);
    std::cout << "Eseguo la print reverse" << std::endl;
    DoubleLinkedList_print_reverse(lst);
    DoubleLinkedList_delete(lst);
}
