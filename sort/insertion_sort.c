#include <stdio.h>
#define LESS(A, B) ((A) < (B))
#define SWAP(A, B) {int temp = A; A = B; B = temp;}
#define VEC_SIZE 50000
typedef int TYPE; //it's needed to change the type of input and output in lines 14,16,20
void insertion_sort(TYPE data[], int l,int r)
{   int i = l+1;
	while(i <= r)
    {   if(LESS(data[i],data[i-1]))
		{	int j = i; TYPE v = data[i];
			while(j >= l && LESS(v,data[j-1]))
				{SWAP(data[j-1],data[j]); j--;}
		}
		i++;}
}
int main(void)
{   TYPE vec[VEC_SIZE]; int i = 0;
    while(scanf("%d",&vec[i++])!=EOF); 
    insertion_sort(vec, 0, --i);
    for(int j = 0 ; j < i; j++)
        printf("%d ",vec[j]);
    printf("\n");
    return 0;}
