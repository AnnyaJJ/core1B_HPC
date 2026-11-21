#include <stdio.h>
#include <omp.h>
int main(void)
{
  int nthread = omp_get_max_threads();
  int thread;
  int indexh = nthread-1;
#pragma omp parallel private(thread) shared(nthread)
  {
    thread = omp_get_thread_num();
    if (thread == indexh)
    printf("Hello, World!!!! I am thread %d of %d\n", thread, nthread);
  }
  return 0;
}
