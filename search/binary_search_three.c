#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct aux{
    Item data;
    struct aux *l, *r;
}NODE;

typedef NODE *THREE;

NODE* init(int item){
    THREE new = malloc(sizeof(NODE));
    new->data = item;
    new->l = NULL;
    new->r = NULL;
    return new;
}

void printThree(THREE root){
    if(root!=NULL){
        printf("%d\n", root->data);
        printThree(root->l);
        printThree(root->r);
    }
}

NODE* search(THREE root, int item){
    if(root == NULL) return NULL;
    if(root->data == item) return root;
    if(root->data > item)
        return search(root->l, item);
    
    return search(root->r, item);
}

NODE* insert(THREE root, NODE* new){
    if(root == NULL) return new;

    if(new->data < root->data)
        root->l = insert(root->l, new);
    else
        root->r = insert(root->r, new);

    return root;
}

NODE* removeRoot(THREE root){////////////////////////////////////
    return root->l;
}

int main() {
    THREE root = NULL;

    root = insert(root, init(7));
    root = insert(root, init(2));
    root = insert(root, init(12));
    root = insert(root, init(8));
    root = insert(root, init(3));
    root = insert(root, init(1));
    root = insert(root, init(5));
    printThree(root);
    printf("\n\n");
    root = removeRoot(root);
    printThree(root);

    printf("(%d)\n",search(root, 2)->data);
    return 0;
}
