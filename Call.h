#ifndef CALL_H
#define CALL_H

class Call
{
private:
    double S;  //current price of the underlying
    double K;  //strike price
    double r;  //risk free rate
    double T;  // time to expiry date

public:
    Call(double S,double K,double r,double T);
    ~Call();
    double CalcPrice(double sigma) const; // price of the call under the Black–Scholes model
    double Bisection(double market_price, double lower_bound, double upper_bound, double error ) const; //implied volatility calculated by bisection method
    double Newton_Raphson(double market_price, double sigma_estimate, double error ) const; //implied volatility calculated by the Newton_Raphson method
};

#endif // CALL_H
