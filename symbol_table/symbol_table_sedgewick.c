//Symbol Table API in Binary Search Three
#include <stdio.h>
#include <stdlib.h>

#define NULLitem ((Item){})
#define info(A) (A.info)
#define key(A) (A.k)
#define less(A, B) ((A) < (B))
#define eq(A, B) ((A) == (B))

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

STnode *STnew(Item x, STnode *l, STnode *r){
    STnode *new = malloc(sizeof(STnode));
    new->left = l;
    new->right = r;
    new->item = x;
    return new;
}

Item STsearch(STnode *root, Key value){//from root search the node with item->key == value
    if(root == NULL) return NULLitem;
    Key aux = key(root->item);//acess the key in ST from actual node/root 
    if(eq(aux, value)) return root->item;
    if(less(aux, value)) return STsearch(root->left, value);
    return STsearch(root->right, value);
}

STnode *insert(STnode *root, Item new){
    if(root == NULL) 
        return STnew(new, NULL, NULL);

    Key new_key = key(new);
    Key actual = key(root->item);
    if(less(actual, new_key)) return insert(root->right, new);
    else if(less(new_key, actual)) return insert(root->left, new);
    root->item = new;
    return root;
}

STnode *min(STnode *node){
    if(node->left == NULL) return node;
    min(node->left);
}

STnode *deleteMin(STnode *node){
    if(node->left == NULL) return node->right;

    node->left = deleteMin(node->left);
    return node;
}

STnode *delete(STnode *root, Key remove){
    if(root == NULL) return NULL;

    //precisamos verificar se o item que queremos remover eh menor ou maior que o atual, caso seja menor, nao faz sentido continuar com a root atual
    //entao, descemos pro prox node a direita ou a esquerda
    Key actual = key(root->item);
    if(less(remove, actual)) root->left = delete(root->left, remove);//o item a ser removido esta na direita
    else if(less(actual, remove)) root->right = delete(root->right, remove);//o item a ser removido esta na esquerda
    else{//o item a ser removido eh o atual
        //um dos filhos ser NULL

        STnode *aux;
        if(root->left == NULL){
            aux = root->right;
            free(root);
            return aux;
        }
        else if(root->right == NULL){
            aux = root->left;
            free(root);
            return aux;
        }

        aux = root;
        root = min(root->right);
        root->right = deleteMin(root->right);
        root->left = aux->left;

        free(aux);
    }

    return root;
}