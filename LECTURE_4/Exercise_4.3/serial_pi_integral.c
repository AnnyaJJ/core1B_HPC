#include <stdio.h>
#include <omp.h>
#include <math.h>
#include <stdlib.h>

double f(double x){
	return 4.0/(1.0 + x*x);
}

int main(int argc, char** argv) {
    // Numerical integration of f(x) = 4/(1+x^2) in [a,b] = [0,1]
    // We use a fixed stepsize ('delta x') here.
    //const long num_steps = 500000000;
    const long num_steps = (long)(atol(argv[1]));
    const double a=0;
    const double b=1;
    const double stepsize = (b-a) / num_steps; // This is 'delta x'
    
    double sum = 0;   // This accumulates the f(x)*'delta x' values (i.e. areas)
       
    double t_0 = omp_get_wtime(); // time stamp
    
    for (int i = 1; i <= num_steps; i++){
        double x = a + (i - 0.5) * stepsize;
        sum += f(x) * stepsize;   // evaluate f(x)*dx and add to accumulator
    }
      
    double t_tot = omp_get_wtime() - t_0; // duration in seconds
    
    printf("\n pi error with %ld steps is %2.16f in %2.16f seconds\n ", num_steps, fabs(sum-M_PI), t_tot);
    
    return 0;
}