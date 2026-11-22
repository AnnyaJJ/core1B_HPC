#include <omp.h>
#include <stdio.h>

int main() {

#pragma omp parallel
  {
    int id = omp_get_thread_num();

    printf("Hello world from thread #%d\n", id);

    if (id == 5) {
      printf("Thread #%d reports: This program uses %d threads.\n",
             id, omp_get_num_threads());
    }
  }

  return 0;
}
