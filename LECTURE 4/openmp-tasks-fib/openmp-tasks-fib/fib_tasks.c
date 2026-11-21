#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

long fib(long n) {
    if (n < 2) return n;
    long x, y;
    #pragma omp task shared(x)
    x = fib(n - 1);
    #pragma omp task shared(y)
    y = fib(n - 2);
    #pragma omp taskwait
    return x+y;
}
int main(int argc, char* argv[]){
    long input = atol(argv[1]);
    long output = 0;
    #pragma omp parallel
    {
    	#pragma omp single
     {
     output = fib(input);
     }
    }
    printf("fib(%ld) = %ld\n", input, output);
    return 0;
}
