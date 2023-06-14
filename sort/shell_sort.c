#include <stdio.h>
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {TYPE t = A; A = B; B = t;}
#define compexch(A, B) if (less(B, A) exch(A, B))
#define VEC_SIZE 50000
typedef int TYPE;

void insertion_sortH(TYPE v[], int l ,int r, int h)
{   for(int i = l+h; i <= r; i++)
    {   int j = i;TYPE temp = v[j];
        while(j>l+h && less(temp, v[j-h]))
        {   v[j] = v[j-h];
            j-=h;
        }
        v[j] = temp;
    }
}

void shell_sort(TYPE v[], int l, int r)
{   int h = 1;
    while(h < (r-l+1)/3) h = 3*h+1;
    for(; h > 0 ; h /= 3)
    {   //insertion_sortH(v, l , r, h);
        for(int i = l+h; i <= r; i++)
            for(int j = i;j>=l+h && less(v[j], v[j-h]);j-=h)
                exch(v[j], v[j-h]);
    }
}

int main(void)
{   TYPE vec[VEC_SIZE]; int i = 0, j = 0;
    while(scanf("%d",&vec[i++])!=EOF);
    shell_sort(vec, 0, --i);
    for(int j = 0 ; j < i; j++)
        printf("%d ",vec[j]);
    printf("\n");
    return 0;
}