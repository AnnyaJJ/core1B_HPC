#include <mpi.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int rank, size;

	int *sendbuf;
	int *recvbuf;

	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int nentries = argc > 1 ? atoi(argv[1]) : 1;

	sendbuf = calloc(nentries, sizeof(*sendbuf));
	recvbuf = malloc(nentries * sizeof(*recvbuf));

	for (int i = 0; i < nentries; i++) {
		sendbuf[i] = rank;
	}

	int other = 1 - rank;   // el rank del otro proceso (con 2 procesos: 0↔1)

	MPI_Sendrecv(sendbuf, nentries, MPI_INT, other, 0,
             recvbuf, nentries, MPI_INT, other, 0,
             MPI_COMM_WORLD, MPI_STATUS_IGNORE);

	printf("[%d] First entry of sendbuf is %d; first of recvbuf is %d\n", rank, sendbuf[0], recvbuf[0]);
	MPI_Finalize();
	return 0;
}
