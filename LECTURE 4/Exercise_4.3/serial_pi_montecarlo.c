#define _XOPEN_SOURCE
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef M_PI
#define M_PI 3.141592653589793
#endif

int accum_count( int n, int *seed ){
	int i, count = 0;
	double x,y;
    
	for ( i = 0; i < n; i++ ){
        x = drand48();
        y = drand48();
		if (x*x + y*y < 1.0){
			count++;
		}
	}
	return count;
}

int main( void ){
	const int n = 500000000;
	int seed = 123456789;
	int count = accum_count( n, &seed );
	printf("count = %d, pi = %2.16f\n", count, 4.0*(double)(count)/(double)(n));
	return 0;
}