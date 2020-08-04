#define _USE_MATH_DEFINES
#include "cdf.h"
#include <cmath>
//an estimate for the cumulative normal distribution function
double cdf(double x) {
    double d = 1/(1 + 0.2316419*x);
    double cdf=(1 - (1/(pow(2*M_PI,0.5)))*exp(-0.5*x*x) * d*(0.319381530 + d*(-0.356563782 + d*(1.781477937 + d*(-1.821255978 + 1.330274429*d)))));
    
    if (cdf < 0) 
        cdf = 1 - cdf;
    return cdf;
}

