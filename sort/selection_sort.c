#include <stdio.h>
#define LESS(A, B) ((A) < (B))
#define SWAP(A, B) {int temp = A; A = B; B = temp;}
#define VEC_SIZE 50000
typedef int TYPE; //it's needed to change the type of input and output in lines 15,17,21
void selection_sort(TYPE data[], int l, int r){
    for(int i = l; i < r ; i++)
    {   int menor = i;
        for(int j = i+1; j < r ;j++){ if(LESS(data[j],data[menor])) menor = j; }
        if(data[i] != data[menor]) SWAP(data[i], data[menor]);}
}

void stable_selection_sort(TYPE data[], int l, int r){
    for(int i = l; i < r; i++){
        int min = i;
        for(int j = i+1 ; j < r ; j++)
            if(data[j] < data[min]) min = j;

        TYPE element = data[min];
        if(min != i){ //already sorted
            for(int k = min-1; k >= i ; k--)
                data[k+1] = data[k];
            data[min] = element;
        }
    }
}

int main(void)
{   TYPE vec[VEC_SIZE]; int i = 0;
    while(scanf("%d",&vec[i++])!=EOF); 
    selection_sort(vec, 0, i-1);
    for(int j = 0 ; j < i-1; j++)
        printf("%d ",vec[j]);
    printf("\n");
    return 0;}
