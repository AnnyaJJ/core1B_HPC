#!/bin/bash
# 1 node
#SBATCH --nodes=2
#SBATCH --ntasks-per-node=2
#SBATCH --job-name="ping.pong"
#SBATCH -o ping-pong.%J.out
#SBATCH -e ping-pong.%J.err
#SBATCH -t 00:01:00
#SBATCH -p shared

module load gcc
module load openmpi

mpicc -o ping-pong ping-pong.c
mpirun ./ping-pong
