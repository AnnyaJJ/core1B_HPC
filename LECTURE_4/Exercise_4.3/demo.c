#define _XOPEN_SOURCE
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
    const size_t N = 5000000;
    double a[N];
    srand48(42);
    for (size_t i=0; i < N; i++){
        a[i] = drand48();
    }
    printf("a[%li] = %f\n", N-2, a[N-2]);
    return 0;
}