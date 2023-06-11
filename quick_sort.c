#include <stdio.h>
#include <stdlib.h>
typedef int TYPE;
#define key(A) (A)
#define less(A, B) (key(A)<key(B))
#define exch(A, B) {TYPE temp = A; A = B; B = temp;}
#define compexch(A, B) if(less(B, A)) exch(A, B) //if B < A, exch

int partition(TYPE a[], int l, int r)
{	int i = l-1, j = r; TYPE v = a[r];

}

void quicksort(TYPE a[], int l, int r)

int main(void){}
