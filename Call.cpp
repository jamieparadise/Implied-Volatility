#include "cdf.h"
#include "Call.h"
#include <cmath>
#include <iostream>
Call::Call(double S,double K, double r, double T):
    S{S},K{K},r{r},T{T}
{
}

Call::~Call()
{
}

double Call::CalcPrice(double sigma) const
{ // This calculates the price of the call under the Black–Scholes model
    double d_1 = log(S/K) + (r + 0.5*sigma*sigma*T)/(sigma*pow(T,0.5));
    double d_2 = d_1 - sigma*pow(T,0.5);
    return S*cdf(d_1) - K*exp(-r*T)*cdf(d_2);
}

double Call::Bisection(double market_price, double lower_bound, double upper_bound, double error ) const{
    //The method finds the midpoint between the two bounds then calculates the price 
    double middle_value{(lower_bound+upper_bound)/2};
    double price_estimate = CalcPrice(middle_value);
    int number_of_iterations{};
    while (middle_value-lower_bound > error){
        if (market_price > price_estimate) {
            lower_bound = middle_value;
        }
        else {
            upper_bound = middle_value;
        }

        middle_value = (lower_bound+upper_bound)/2;
        price_estimate = CalcPrice(middle_value);
        number_of_iterations++;
    } 
    std::cout <<"The bisection method took "<< number_of_iterations <<" iterations." <<std::endl;
  return middle_value;
} 

double Call::Newton_Raphson(double market_price, double sigma_estimate, double error ) const{
    double price_estimate{};
    int number_of_iterations{};
    double vega{};
    do{
        price_estimate = CalcPrice(sigma_estimate);
        vega = S * pow(T/(M_PI*2),0.5);
        sigma_estimate = sigma_estimate - (price_estimate - market_price)/vega;
        number_of_iterations++;
    } while (fabs((price_estimate - market_price)/vega) > error);
    std::cout <<"The bisection method took "<< number_of_iterations <<" iterations." <<std::endl;
    return sigma_estimate;
}