#include <iostream>
#include <omp.h>
using namespace std;

/*
    f(x) = 4/(1 + x^2)
    area under this curve from 0 to 1 interval. 
*/
long numSteps = 100000;
double deltaX;

void computePiSerial(){
    double x, pi = 0.0;
    deltaX = 1.0/(double(numSteps));
    for(int i = 0;i<numSteps;i++){
        x = (i+0.5)*(deltaX);
        double fx = (4.0/(1+x*x))*deltaX;
        pi = pi + fx;
    }
    cout<<pi;
}

int main(){
    computePiSerial();
    return 0;
}