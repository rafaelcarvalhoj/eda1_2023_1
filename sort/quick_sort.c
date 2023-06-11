#include <stdio.h>
#include <stdlib.h>
typedef int TYPE;
#define key(A) (A)
#define less(A, B) (key(A)<key(B))
#define exch(A, B) {TYPE temp = A; A = B; B = temp;}
#define compexch(A, B) if(less(B, A)) exch(A, B) 

int partitionRibasNIP(TYPE a[], int l, int r)
{   TYPE pivot = a[r];
    int pivot_position, size = r-l+1;
    TYPE *smaller = malloc(sizeof(TYPE)*size);
    TYPE *bigger = malloc(sizeof(TYPE)*size);
    int s = 0, b = 0, i;
    for(i = l; i < r ; i++)
    {   if(less(pivot, a[i])) smaller[s++] = a[i];
        else bigger[b++] = a[i];
    }
    i = l;
    for(int j = 0; j < s ; j++)
        a[i++] = smaller[j];
    
    pivot_position = i;
    a[i++] = pivot;

    for(int j = 0; j < b ; j++)
        a[i++] = bigger[j];
    
    free(smaller);
    free(bigger);
    return pivot_position;
}

int partitionRafael(TYPE a[], int l, int r){
    TYPE pivot = a[r];
    int pivot_position;
}


int partition(TYPE a[], int l, int r)
{	int i = l-1, j = r; TYPE v = a[r];

}

void quicksort(TYPE a[], int l, int r);

int main(void){}
