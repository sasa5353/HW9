//
// Created by alex on 10.03.2020.
//

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

class Polynomial {
private:
    unsigned int deg;
    double *koef;
    void correctDeg();

public:
    Polynomial();
    Polynomial(unsigned int, double *);
    Polynomial(const Polynomial &);
    ~Polynomial();
    
    unsigned int getDeg();
    double getKoef(unsigned int);
    friend Polynomial operator-(const Polynomial &);
    Polynomial operator+(const Polynomial &);
    Polynomial operator=(const Polynomial &);
    friend Polynomial operator+=(Polynomial &, Polynomial &);
    friend Polynomial operator-=(Polynomial &, Polynomial &);
    friend Polynomial operator/(Polynomial &, Polynomial &);
    friend Polynomial operator/=(Polynomial &, Polynomial &);
    friend Polynomial operator*=(Polynomial &, Polynomial &);
    friend Polynomial operator%(Polynomial &, Polynomial &);
    friend Polynomial operator*(Polynomial &, double);
    friend Polynomial operator*(double, Polynomial &);
    friend Polynomial operator*(Polynomial &, Polynomial &);
    friend Polynomial operator-(Polynomial &, Polynomial &);
    friend Polynomial multConst(double, Polynomial &);
    friend Polynomial multPolynomial(Polynomial &, Polynomial &);
};

#endif
