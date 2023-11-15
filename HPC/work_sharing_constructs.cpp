#include <chrono>
#include <iostream>
#include <omp.h>
using namespace std;

/*

omp parallel for :
syntax :
    #pragma omp parallel for {
        for(<work>;<work>;<work>){
            <stmts>
        }
    }

things to take care of (Programmer responsiblity):
    1) omp parallel for should not be used with data dependencies or when lhs
and rhs of any computation might alais, it could introduce data hazard. for ex :
c[i] = a[i] + c[i-1], this has loop carried dependence. Hence omp parallel for
can not be used.

    2) Threads should not write to shared data space without using thread sync,
like atomic or critical section.

    3) in parallel for construct no allocation of jobs required manually, omp
does it by default.

    4) Threads will join at the end of for loop. Spwan at the beginning.

Data sharing : Reduction (only (commutative and associative) opreations allowed for reduction where order does not matter)
example : summation of arrays is a common operation. 
Syntax : 
    #pragma omp parallel for reduction (+: <var>)
    for(<work>;<work>;<work>){
        <var> += <data_space>
    }
    
    
    so what is the use of this? is it the same as omp parallel for? Yes and No. 
    This reduction opreation with parallel for loops auto reduction, using the reduction <var> 
    say summing of 1000 elements of an array into reduction variable sum with 10 threads, it does allocation of 100 elements per thread and a thread local variable holds the summation result and instead of collecting the final output in variable sum linearly, it collets in the tree format. And adds the subtree computations using omp parallel constructs, As follows. Which is faster and more efficent for larger data space sizes. 

    s0  s1  s2  s3  s4  s5  s6  s7  s8  s9
      s01     s23     s45     s67     s89 
          s0123           s4567     s89 
                s01234567       s89
                       s0123456789
*/

long numSteps = 1000000;
double deltaX;

void piComputationUsingReduction() {
  double x, pi = 0.0;
  deltaX = 1.0 / (double(numSteps));
#pragma omp parallel for reduction(+ : pi)
  for (int i = 0; i < numSteps; i++) {
    x = (i + 0.5) * (deltaX);
    double fx = (4.0 / (1 + x * x)) * deltaX;
    pi = pi + fx;
  }

  cout << pi;
}

int main() { piComputationUsingReduction(); }