#!/bin/bash

#SBATCH --nodes=1
#SBATCH --cores=4
#SBATCH --job-name="threadtest"
#SBATCH -o threadtest.%J.out
#SBATCH -e threadtest.%J.err
#SBATCH -t 00:01:00
#SBATCH -p shared

module load gcc
gcc -fopenmp -o threadtest threadtest.c
export OMP_NUM_THREADS=4
./threadtest


