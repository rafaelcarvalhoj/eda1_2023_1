#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int TYPE;

#define key(A) (A)
#define less(A, B) (key(A)<key(B))
#define exch(A, B) {TYPE temp = A; A = B; B = temp;}
#define compexch(A, B) if(less(B, A)) exch(A, B)
#define VEC_SIZE 50000

TYPE aux[VEC_SIZE];
void merge(TYPE *v, int l, int m, int r)
{   int i=l, j=m+1, k=l;
    while(i<=m && j<=r){aux[k++] = less(v[i], v[j]) ? v[i++] : v[j++];}
    while(i<=m){aux[k++] = v[i++];}
    while(j<=m){aux[k++] = v[j++];}
    for (i = l; i <= r; i++){v[i] = aux[i];}
}
void merge_sort(TYPE *v, int l, int r)
{   int m = (l+r)/2;
    if(r<=l) return;
    merge_sort(v, l, m);
    merge_sort(v, m+1, r);
    merge(v, l, m, r);
}

int partitionSedgewick(TYPE a[], int l, int r){
    int i = l-1, j = r, piviot = a[r];
    for(;;){
        while(a[--i]<piviot);//finding the element for the right partition
        while(piviot<a[--j]) if(j==l) break; //already sorted
        if(i>=j) break;
        exch(a[i],a[j]);
    }

    return j;
}

void quick_sort_RM3(TYPE a[], int l, int r){// 10|20% better
    if(r<=l) return;

    compexch(a[l], a[(l+r)/2]);
    compexch(a[l], a[r]);
    compexch(a[r], a[(l+r)/2]);

    int p = partitionSedgewick(a, l, r);

    quick_sort_RM3(a, l, p-1);
    quick_sort_RM3(a, l , p+1);
}

void insertion_sort(TYPE data[], int l,int r)
{   int i = l+1;
	while(i <= r){   
        if(less(data[i],data[i-1])){	
            int j = i; TYPE v = data[i];
			while(j >= l && less(v,data[j-1])){
                exch(data[j-1],data[j]); j--;
            }
		}
		i++;
        }
}


void intro_sort(TYPE a[], int l, int r, int maxDepth){
    if(l-r <=20){
        insertion_sort(a, l, r);
    }
    else if(maxDepth == 0){
        merge_sort(a, l ,r);
    }
    else{
        compexch(a[l], a[(l+r)/2]);
        compexch(a[l], a[r]);
        compexch(a[r], a[(l+r)/2]);

        int p = partitionSedgewick(a, l, r);
        intro_sort(a, l, p-1, maxDepth-1);
        intro_sort(a, p+1, r, maxDepth-1);
    }

}   


void intro(TYPE a[], int l, int r){
    int maxDepth = 2*((int)log2((double)r-l+1));
    intro_sort(a, l, r, maxDepth);
}