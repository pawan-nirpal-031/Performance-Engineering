export OMP_NUM_THREADS=$1 
g++ $2 -fopenmp -o $2.o 
./$2.o