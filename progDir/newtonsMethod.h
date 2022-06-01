//
// Created by alex on 23.03.2020.
//

#ifndef TASK9_NEWTONSMETHOD_H
#define TASK9_NEWTONSMETHOD_H

#include <cmath>
#include "func.h"
#include "quad/Gauss.h"

double *newtonMethod(double*(*)(double*), double*, unsigned int);
double deltaNorm(double*, double*);
double **jacobi(double *(*)(double *), double *);
const unsigned int nForNewton = length;
const double step = 1e-7;

#endif //TASK9_NEWTONSMETHOD_H
