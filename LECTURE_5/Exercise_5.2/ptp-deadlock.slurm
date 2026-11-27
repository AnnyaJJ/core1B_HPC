#!/bin/bash
# 1 node
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=2
#SBATCH --job-name="ptp-deadlock"
#SBATCH -o ptp-deadlock.%J.out
#SBATCH -e ptp-deadlock.%J.err
#SBATCH -t 00:01:00
#SBATCH -p shared

module load gcc openmpi

mpicc -optp-deadlock ptp-deadlock.c
mpirun -n 2 .ptp-deadlock <nentries>

