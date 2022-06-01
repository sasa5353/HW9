//
// Created by alex on 20.03.2020.
//

#include "quadGauss.h"

double integrate(double(*funcPointer)(double, int), double a, double b, unsigned int n,
                 const double *rootsLegendre, const double *coefficientsGaussQuad, unsigned int j) {
    double integral = 0.0;
    for (unsigned int i = 0; i < n; i++) {
        integral += funcPointer((a + b) / 2 + (b - a) / 2 * rootsLegendre[i], j) * coefficientsGaussQuad[i];
    }
    
    integral *= (b - a) / 2;
    return integral;
}
