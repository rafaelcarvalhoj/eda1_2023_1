#include <stdio.h>
#define LESS(A, B) ((A) < (B))
#define SWAP(A, B) {int temp = A; A = B; B = temp;}
#define VEC_SIZE 1000
typedef int TYPE; //it's needed to change the type of input and output in lines 13,15,19
void bubble_sort(TYPE data[],int l)
{   for(int j = l; j > 1 ; j--)
        for(int i = 1 ; i < j ; i++)
            if(LESS(data[i],data[i-1])) SWAP(data[i],data[i-1]);}
int main(void)
{   TYPE vec[VEC_SIZE]; int i = 0;
    while(scanf("%d",&vec[i++])!=EOF);
    bubble_sort(vec, i-1);
    for(int j = 0 ; j < i-1; j++)
        printf("%d ",vec[j]);
    printf("\n");
    return 0;}
