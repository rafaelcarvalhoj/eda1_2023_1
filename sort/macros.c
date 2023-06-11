#include <stdio.h>
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {TYPE temp = A; A = B; B = temp;}
#define compexch(A, B) if (less(A, B) exch(A, B))