# 1 core
#SBATCH -n 1
#SBATCH --job-name="strong"
#SBATCH -o strong.%J.out
#SBATCH -e strong.%J.err
#SBATCH -t 00:01:00
#SBATCH -p test

module load gcc

gcc strong.c -o strong
./strong
