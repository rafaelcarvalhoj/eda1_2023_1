#include <stdio.h>
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {TYPE temp = A; A = B; B = temp;}
#define compexch(A, B) if (less(B, A) exch(A, B))