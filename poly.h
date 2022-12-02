//
//  polynomial.h
//  exercise3
//
//  Created by jane cheong  on 06/11/2022.
//

#ifndef polynomial_h
#define polynomial_h
#include <iostream>
class polynomial
{
public:
    polynomial();
    polynomial(int deg, double coef[]);
    polynomial(const polynomial & c); // copy constructor
    polynomial (polynomial && c); //move constructor
    polynomial(double const_term);
    ~polynomial();
    void print(std::ostream & out = std::cout) const;
    polynomial & operator= (const polynomial & c); // copy assignment
    polynomial & operator= (polynomial && c);//move assignment

private:
   int degree;
    double *coefficient;
};
std::ostream & operator<<(std::ostream & out, const polynomial &s);
#endif /* polynomial_h */
