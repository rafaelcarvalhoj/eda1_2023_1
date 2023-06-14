#include <stdio.h>
typedef int TYPE;
#define VEC_SIZE 50000
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
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
int main(void)
{   TYPE vec[VEC_SIZE]; int i = 0, j = 0;
    while(scanf("%d",&vec[i++])!=EOF);
    merge_sort(vec, 0, --i);
    for(int j = 0 ; j < i; j++)
        printf("%d ",aux[j]);
    printf("\n");
    return 0;
}
