#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;
struct node {
    int data;
    link next;
};

//merge de duas listas
link merge(link a, link b){
    struct node new_head;
    link p_head = &new_head;
    while(a!=NULL && b!=NULL){
        if(a->data < b->data){
            p_head->next = a;
            p_head = p_head->next;
            a = a->next;
        }
        else{
            p_head->next = b;
            p_head = p_head->next;
            b = b->next;
        }
    }

    if(a != NULL){
        p_head->next = a;
    }else{
        p_head->next = b;
    }
    return new_head->next;
}
