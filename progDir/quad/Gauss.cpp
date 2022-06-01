//
// Created by alex on 19.03.2020.
//

#include "Gauss.h"

double *gaussMod(double **a, double *b, int n) {
    double *x, maxVal;
    const double eps = 1.0e-15;
    x = new double[n];
    double tmp;
    int indexOfMaxVal;
    for (int i = 0; i < n; i++) {
        maxVal = fabs(a[i][i]);
        indexOfMaxVal = i;
        for (int j = i + 1; j < n; j++) {
            if (fabs(a[j][i]) > maxVal) {
                maxVal = fabs(a[j][i]);
                indexOfMaxVal = j;
            }
        }
        
        for (int j = 0; j < n; j++) {
            tmp = a[i][j];
            a[i][j] = a[indexOfMaxVal][j];
            a[indexOfMaxVal][j] = tmp;
        }
        tmp = b[i];
        b[i] = b[indexOfMaxVal];
        b[indexOfMaxVal] = tmp;
        for (int j = i; j < n; j++) {
            tmp = a[j][i];
            if (fabs(tmp) > eps) {
                for (int k = 0; k < n; k++) {
                    a[j][k] /= tmp;
                }
                b[j] /= tmp;
                if (i != j) {
                    for (int k = 0; k < n; k++) {
                        a[j][k] -= a[i][k];
                    }
                    b[j] -= b[i];
                }
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = 0; j < i; j++) {
            b[j] -= a[j][i] * x[i];
        }
    }
    return x;
}
