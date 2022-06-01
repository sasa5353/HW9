//
// Created by alex on 23.03.2020.
//

#include "func.h"

double X_1[length];

double *f(double t, double *X) {
    X_1[0] = X[0];
    X_1[1] = X[1];
    return X_1;
}
