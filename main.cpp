//
//  main.cpp
//  exercise3
//
//  Created by jane cheong  on 06/11/2022.
//
#include "poly.h"
#include <iostream>

polynomial::polynomial(){
    degree=1;
    coefficient=new double[1];
    coefficient[0] = 0.0;
}

 polynomial::polynomial(int k,double coef[]){
     degree = k;
     coefficient = new double[k];
    for (int i=0;i <= degree; i++){
    coefficient[i]=coef[i];
    }
}

polynomial::polynomial(double const_term){
    degree = 1;
    coefficient = new double [1];
    coefficient[0] = const_term;
}

polynomial::~polynomial(){
        delete [] coefficient;
}

void polynomial::print(std::ostream & out) const {
    if (degree == 0) {
        return;
    }
 
    for (int i = degree; i > 0; i--)
        out << coefficient[i] << "x^" << i << " + ";
    out << coefficient[0];
}
 
std::ostream & operator<<(std::ostream & out, const polynomial &s) {
    s.print(out);
    return out;
}

polynomial::polynomial(const polynomial & c){}; // copy constructor

//polynomial (polynomial && c); //move constructor
////copy
//polynomial::polynomial(const polynomial &c){}

// move assignment
polynomial & polynomial::operator= (polynomial&& c){
    std :: cout << "Move assignment operator for String class got called." << std :: endl;
   if (this != &c)
         {
             degree = c.degree;
             coefficient = c.coefficient;
             c.degree = 0;
             c.coefficient = nullptr;
            }
            return (*this);
}

////move assignment
//polynomial::polynomial(polynomial&& c){
//    coefficient=c.coefficient;
//    degree=c.degree;
//        {
//            c.coefficient = nullptr;
//        }
//}
//polynomial& polynomial::operator=(polynomial&& c){
//            delete [] coefficient;
//            coefficient = c.coefficient;
//            c.coefficient = nullptr;
//            *this = std::move(c);
//            return *this;
//        }
//


int main(){
    double coef[]={1,2,3,4,5};
    polynomial p1(4,coef);
    std::cout << "The polynomial p1 is " << p1 << std::endl;
//    std::cout << "copy polynomial is" << std::endl;
//    polynomial p2(p1);
//    std::cout << "move assignment" << std::endl;
   polynomial p3;
   p3=std::move(p1);
    return 0;
}
