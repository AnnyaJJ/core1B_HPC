#!/bin/bash
# 1 node
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=2
#SBATCH --job-name="ptp-deadlock"
#SBATCH -o core1B_HPC/LECTURE_5/Exercise_5.2/ptp-deadlock.%J.out
#SBATCH -e core1B_HPC/LECTURE_5/Exercise_5.2/ptp-deadlock.%J.err
#SBATCH -t 00:10:00
#SBATCH -p shared

module load gcc openmpi
mpicc -o ptp-deadlock ptp-deadlock.c

for n in 1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 16384 32768 65536 131072; do
    echo "Probando nentries = $n"
    timeout 10 mpirun -n 2 ./ptp-deadlock $n
    if [ $? -ne 0 ]; then
        echo ">>> Falló o se colgó con nentries = $n"
        break
    fi
done

