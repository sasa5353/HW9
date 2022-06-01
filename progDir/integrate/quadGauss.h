//
// Created by alex on 20.03.2020.
//

#ifndef INTEGRATERGAUSS_QUADGAUSS_H
#define INTEGRATERGAUSS_QUADGAUSS_H

double integrate(double(*)(double, int), double, double, unsigned int,
                 const double*, const double*, unsigned int);

#endif //INTEGRATERGAUSS_QUADGAUSS_H

