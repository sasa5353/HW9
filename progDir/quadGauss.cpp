//
// Created by alex on 23.03.2020.
//

#include "quadGauss.h"

double integralForAdams(int j, bool B) {
    int nForGauss = n / 2 + n % 2;
    double *ans = rootsLegendre(nForGauss);
    double **L, *R, *x;
    L = new double *[nForGauss + 1];
    R = new double[nForGauss + 1];
    for (int i = 0; i < nForGauss; i++) {
        L[i] = new double[nForGauss + 1];
        for (int k = 0; k < nForGauss; k++) {
            L[i][k] = pow(ans[k], i);
        }
    }
    for (int i = 0; i < nForGauss; i++) {
        R[i] = (double) 2.0 * ((i + 1) % 2) / (i + 1);
    }
    x = gaussMod(L, R, nForGauss);
    double (*funcPointer)(double, int) = B ? funcB : funcA;
    
    double integral = integrate(funcPointer, 0.0, 1.0, nForGauss, ans, x, j);
    
    delete[] ans;
    delete[] x;
    delete[] R;
    for (int i = 0; i < nForGauss; i++) {
        delete[] L[i];
    }
    delete[] L;
    return integral;
}
