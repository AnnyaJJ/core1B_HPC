#include <stdio.h>
#include <stdlib.h>

// Serial version:
long fib(long n) {
    if (n < 2) return n;
    long x = fib(n - 1);
    long y = fib(n - 2);
    return x+y;
}
int main(int argc,char* argv[]){
    long input = atoi(argv[1]);
    long output = fib(input);
    printf("fib(%ld) = %ld\n", input, output);
    return 0;
}
