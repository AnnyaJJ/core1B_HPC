#!/bin/bash

#SBATCH -n 1
#SBATCH --job-name="lscpu"
#SBATCH -o lscpu.%J.out
#SBATCH -e lscpu.%J.err
#SBATCH -t 00:01:00
#SBATCH -p test

lscpu
