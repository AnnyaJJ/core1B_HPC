#define _XOPEN_SOURCE
#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

double random_value( int *seed ){
	double r;
	
	*seed = ( *seed % 65536 );
	*seed = ( ( 3125 * *seed ) % 65536 );
	r = ( double ) ( *seed ) / 65536.0;
	
	return r;
}

void fill( int n, int *seed ){
	int i;
	int my_id;
	int my_seed;
	double x[n];
	
	#pragma omp parallel private ( i, my_id, my_seed ) shared ( n, x )
	{
		my_id = omp_get_thread_num ( );
		my_seed = *seed + my_id;
		#pragma omp for
		for ( i = 0; i < n; i++ ){
			x[i] = random_value ( &my_seed );
		}
	}
	// Note: this is a lot of printing for large n!
   // You should add a check so it only prints if n is small.
	for (i = 0; i < n; i++){
			printf ( "x[%d] = %lf\n", i, x[i] );
	}

	return;
}

int main( void ){
    int n = 100;
    int seed = 123456789;
    fill( n, &seed );
    return 0;
}