//
// Created by alex on 23.03.2020.
//

#include "newtonsMethod.h"

double *newtonMethod(double *(*funcPointer)(double *), double *X0, unsigned int maxIter) {
    double *X1, *X2;
    double **matrix;
    X1 = new double[nForNewton];
    X2 = new double[nForNewton];
    for (unsigned int i = 0; i < nForNewton; i++) {
        X2[i] = X0[i];
    }
    double *tmp;
    double fX1[nForNewton];
    for (unsigned int iter = 0; (iter < 15) || ((iter < maxIter) && deltaNorm(X1, X2) > 1e-7); iter++) {
        for (unsigned int i = 0; i < nForNewton; i++) {
            X1[i] = X2[i];
        }
//        fX1 = new double[nForNewton];
        for (unsigned int i = 0; i < nForNewton; i++) {
            fX1[i] = -funcPointer(X1)[i];
        }
        matrix = jacobi(funcPointer, X1);
        tmp = gaussMod(matrix, fX1, nForNewton);
        for (unsigned int i = 0; i < nForNewton; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
//        delete[] fX1;
        for (unsigned int i = 0; i < nForNewton; i++) {
            X2[i] = X1[i] + tmp[i];
        }
        delete[] tmp;
    }
    delete[] X1;
    return X2;
}

double deltaNorm(double *X1, double *X2) {
    double result = 0.0;
    double tmp;
    for (unsigned int i = 0; i < nForNewton; i++) {
        tmp = X2[i] - X1[i];
        result += tmp * tmp;
    }
    return sqrt(result);
}

double **jacobi(double *(*funcPointer)(double *), double *X) {
    double **a;
    double tmp[nForNewton];
    a = new double *[nForNewton];
    //tmp = new double[nForNewton];
    for (unsigned int i = 0; i < nForNewton; i++) {
        tmp[i] = X[i];
    }
    for (unsigned int i = 0; i < nForNewton; i++) {
        a[i] = new double[nForNewton];
        for (unsigned int j = 0; j < nForNewton; j++) {
            tmp[j] += step;
            a[i][j] = ((*funcPointer)(tmp)[i] - (*funcPointer)(X)[i]) / step;
            tmp[j] -=step;
        }
    }
    //delete[] tmp;
    return a;
}
