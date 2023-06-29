#include <stdio.h>
#include <stdlib.h>

typedef int Item;

Item search(Item v[], int l, int r, Item k){
   if(l>r) return NULL;
   int m = (l+r)/2;
   if(v[m] == k) return v[m];
   if(k<v[m]) return search(v, l, m-1, k);

   return search(v, m+1, r, k);
}

int main(){
    Item vector[] = {1, 2, 3, 4, 5};
    int result = search(vector, 0, 4, 3);
    printf("%d\n",result);
    return 0;
}