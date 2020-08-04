#define _USE_MATH_DEFINES
#include "Call.h"
#include "cdf.h"
#include <cmath>
#include <iostream>

int main(int argc, char **argv)
{
    double S = 100;  //  price of underlying spot
    double K = 95;  // strike price
    double r = 0.05;   // risk-free rate 
    double T = 1;    // time until expiry
    double call_mrk_price = 10.5; // the market price of a call

    // Create the call object
    Call call(S, K, r, T);
    //set some lower and upper bounds on the volatility
    double lower_bound{.05};
    double upper_bound{.35};
    //set the upper bound for the error of the volatility
    double error {0.00001};
    std::cout << "The implied volaitility given by the Bisection method: " << call.Bisection(call_mrk_price, lower_bound,upper_bound,error)<<std::endl;
    std::cout << "The implied volaitility given by the Newton-raphson method: " << call.Newton_Raphson(call_mrk_price,lower_bound,error)<<std::endl;
	return 0;
}
