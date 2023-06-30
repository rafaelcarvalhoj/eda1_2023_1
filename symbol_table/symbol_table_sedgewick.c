//Symbol Table API in Binary Search Three
#include <stdio.h>
#include <stdlib.h>

#define NULLitem ((Item){}) //return null Item
#define info(A) (A.info) //return the info of ST struct
#define key(A) (A.key)
#define less(A, B) ((A) < (B))
#define eq(A, B) ((A)==(B))

//Symbol Table -> Item
typedef int Key;
typedef struct data{
    Key k;
    char info[100];
}Item;

//Node three
typedef struct node{
    Item item;
    struct node *left, *right;
}STnode;

STnode *new(Item x, STnode *l, STnode *r){
    STnode *new = malloc(sizeof(STnode));
    new->left = l;
    new->right = r;
    new->item = x;
    return new;
}

Item STsearch(STnode *root, Key value){//from root search the node with item->key == value
    if(root == NULL) return NULLitem;
    Key aux = key(root->item);//acess the key in ST from actual node/root 
    if(eq(aux, value)) return root->Item;
    if(less(aux, value)) return STsearch(root->left, value);
    return STsearch(root->right, value);
}

