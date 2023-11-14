#include <chrono>
#include <iostream>
#include <omp.h>
using namespace std;

/*
    f(x) = 4/(1 + x^2)
    area under this curve from 0 to 1 interval.
*/
long numSteps = 100000;
double deltaX;

void computePiSerial() {
  double x, pi = 0.0;
  deltaX = 1.0 / (double(numSteps));
  for (int i = 0; i < numSteps; i++) {
    x = (i + 0.5) * (deltaX);
    double fx = (4.0 / (1 + x * x)) * deltaX;
    pi = pi + fx;
  }
  cout << pi;
}

void computePiParallel() {
  // This implementation can be optimized using 2d padding for avoiding chaos
  // caused in cache access, and it slows down significantly, this 1d array can
  // be modelled using 2d array with coloumn 0 as array elements and rest as 0.
  // providing an uniform cache access pattern.
  const int MAX_NUM_T = 100;
  int numThreads;
  double pi = 0.0;
  double sum[MAX_NUM_T];
  deltaX = 1.0 / (double(numSteps));
#pragma omp parallel
  {
    double x;
    int id = omp_get_thread_num();
    int nThreads = omp_get_num_threads();
    // let only one thread record this thread count. To prevent all threads
    // writing to it.
    if (id == 0)
      numThreads = nThreads;
    for (int i = id; i < numSteps; i += nThreads) {
      x = (i + 0.5) * deltaX;
      double fx = (4.0 / (1.0 + x * x)) * deltaX;
      sum[id] += fx;
    }
  }
  // This serial loop is a performance bottleneck, can we elimiate it?
  for (int i = 0; i < numThreads; i++)
    pi += sum[i];
  cout << pi;
}

void computePiParallelCriticalSection() {}

int main() {
  auto start_time = std::chrono::high_resolution_clock::now();
  computePiParallel();
  auto end_time = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(
      end_time - start_time);
  std::cout << "Time taken by function f: " << duration.count()
            << " nanoseconds" << std::endl;
  return 0;
}