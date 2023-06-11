#include <stdio.h>
#define LESS(A, B) ((A) < (B))
#define SWAP(A, B) {int temp = A; A = B; B = temp;}
#define VEC_SIZE 50000
typedef int TYPE; //it's needed to change the type of input and output in lines 14,16,20
void insertion_sort(TYPE data[], int r,int l)
{   int i = r+1;
	while(i < l) 
    {   if(LESS(data[i],data[i-1]))
		{	int j = i;
			while(j > r && LESS(data[j],data[j-1]))
			{	SWAP(data[j-1],data[j]);
				j--;
			}

		}
		i++;
	}
}
int main(void)
{   TYPE vec[VEC_SIZE]; int i = 0;
	char input[100];
    fgets(input, sizeof(input), stdin);
    while (sscanf(input, "%d", &vec[i++]) != EOF) {
        fgets(input, sizeof(input), stdin);
    }
    insertion_sort(vec, 0, --i);
    for(int j = 0 ; j < i; j++)
        printf("%d ",vec[j]);
    printf("\n");
    return 0;}
