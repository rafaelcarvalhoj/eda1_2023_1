#include <stdio.h>
#include <stdlib.h>

typedef int TYPE;

#define key(A) (A)
#define less(A, B) (key(A)<key(B))
#define exch(A, B) {TYPE temp = A; A = B; B = temp;}
#define compexch(A, B) if(less(B, A)) exch(A, B) 

int partitionRibasNIP_exemple(TYPE a[], int l, int r)
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

int partitionRafael(TYPE a[], int l, int r){//sedgewick
    TYPE pivot = a[r];
    int i=l , j=r+1;
    while(i < j)
    {   while(a[++i]<=pivot && i < r);
        while(a[--j]>pivot && j > l);
        if(i < j) exch(a[i],a[j]);
    }
    exch(a[r],a[j]);
    return j;
}

int partitionCormem(TYPE a[], int l, int r){
    int pivot = a[r];
    int j =l;
    for(int i = l; i<r ; i++)
        if(less(v[i], pivot)){exch(pivot, v[i]); j++;}

    exch(v[r],v[j]);
    return j;
}

int partitionSedgewick(TYPE a[], int l, int r){
    int i = l-1, j = r, piviot = a[r];
    for(;;){
        while(v[--i]<piviot);//finding the element for the right partition
        while(piviot<v[--j]) if(j==l) break; //already sorted
        if(i>=j) break;
        exch(v[i],v[j]);
    }

    return j;
}

void quick_sort(TYPE a[], int l, int r){
    if(r<=l) return;
    
    int p = partitionCORMEM(v, l, r);
	quick_sortC(v, l, p-1);
	quick_sortC(v, p+1, r);
}

void quick_sort_RM3(TYPE a[], int l, int r){// 10|20% better
    if(r<=l) return;

    compexch(v[l], v[(l+r)/2]);
    compexch(v[l], v[r]);
    compexch(v[r], v[(l+r)/2]);

    int p = partitionSedgewick(a, l, r);

    quick_sort_RM3(a, l, p-1);
    quick_sort_RM3(a, l , p+1);
}