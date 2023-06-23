#include <stdio.h>
#include <stdlib.h>
typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {Item temp = A; A = B; B = temp;}
#define compexch(A, B) if (less(B, A) exch(A, B))

static Item *pq;
static int N;

void PQinit(int maxN){
    pq = malloc((maxN+1)*sizeof(Item));
    N = 0;
}

int PQempty(){
    return N == 0;
}

void PQfixUp(int k){
    while(k>=1 && less(pq[k],pq[k/2])){
        exch(pq[k],pq[k/2]);
        k /= 2;
    }
}

void PQfixDown(int k, n){
    int j;
    while(2*k < n){
        j = k*2;
        if(j<n && less(pq[j], pq[j+1])) j++;
        if(!less(pq[k], pq[j])) break;
        exch(pq[k], pq[j]);
        k = j;
    }
}

void PQinsert(int k){
    pq[N++] = k;
    PQfixupUp(N);
}

Item PQdelMax(){
    exch(pq[1], pq[N]);
    PQfixDown(1, N-1);
    return pq[N--];
}