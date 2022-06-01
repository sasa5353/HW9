//
// Created by alex on 23.03.2020.
//

#include "adamsExtrapolation.h"

void adamsExtrapolation(std::string s) {
    double A[n];
    A[0] = (double) 1.0 / fact(n - 1);
    for (long long unsigned i = 1; i < n; i++) {
        A[i] = -A[i - 1] * ((double) (n - i)) / (double) i;
    }
    for (unsigned int i = 0; i < n; i++) {
        A[i] *= integralForAdams(i, false);
    }
    rungeKuttas(s, true, false);
    double t_i;
    std::ifstream in;
    in.open(s);
    const unsigned long long p = ((b - a) / h);
    const int devid = n;
    double **X;
    X = new double *[devid];
    for (long long unsigned i = 0; i < devid; i++) {
        in >> t_i;
        X[i] = new double[length];
        for (int j = 0; j < length; j++) {
            in >> X[i][j];
        }
    }
    in.close();
    std::ofstream out;
    out.setf(std::ios::scientific);
    out.precision(10);
    out.open(s, std::ios::app);
    double tmp[length];
    
    for (long long unsigned i = devid - 1; i < p; i++) {
        // X[i + 1] = new double[length];
        for (int j = 0; j < length; j++) {
            tmp[j] = 0.0;
        }
        for (long long unsigned j = 0; j < devid; j++) {
            t_i = a + (i - j) * h;
            for (int k = 0; k < length; k++) {
                tmp[k] += A[j] * f(t_i, X[(i - j) % devid])[k];
            }
        }
        for (int j = 0; j < length; j++) {
            X[(i + 1) % devid][j] = X[i % devid][j] + h * tmp[j];
        }
        t_i = a + (i + 1) * h;
        out << t_i << " ";
        for (int j = 0; j < length; j++) {
            out << X[(i + 1) % devid][j] << " ";
        }
        out << std::endl;
    }
    out.close();
    for (long long unsigned i = 0; i < devid; i++) {
        delete[] X[i];
    }
    delete[] X;
    // return X;
}

double fact(unsigned int p) {
    return (p == 0) ? 1 : p * fact(p - 1);
}
