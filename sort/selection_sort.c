#include <stdio.h>
#define LESS(A, B) ((A) < (B))
#define SWAP(A, B) {int temp = A; A = B; B = temp;}
#define VEC_SIZE 50000
typedef int TYPE; //it's needed to change the type of input and output in lines 15,17,21
void selection_sort(TYPE data[], int r, int l){
    for(int i = r; i < l ; i++)
    {   int menor = i;
        for(int j = i+1; j < l ;j++){ if(LESS(data[j],data[menor])) menor = j; }
        if(data[i] != data[menor]) SWAP(data[i], data[menor]);}
}
int main(void)
{   TYPE vec[VEC_SIZE]; int i = 0;
    while(scanf("%d",&vec[i++])!=EOF); 
    selection_sort(vec, 0, i-1);
    for(int j = 0 ; j < i-1; j++)
        printf("%d ",vec[j]);
    printf("\n");
    return 0;}
