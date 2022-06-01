//
// Created by alex on 23.03.2020.
//

#include "rungeKuttas.h"

void rungeKuttas(std::string s, bool adams, bool adamsB) {
    std::ofstream out;
    out.setf(std::ios::scientific);
    out.precision(10);
    out.open(s);
    const unsigned long long p = adams?n - 1 - adamsB:((b - a) / h);
    const int devid = 2;
    double **X;
    X = new double *[devid];
    for (int i = 0; i < devid; i++) {
        X[i] = new double[length];
    }
    for (int i = 0; i < length; i++) {
        X[0][i] = X_0[i];
    }
    
    double k[4][length];
    double tmp[length];
    double t_i = a;
    out << t_i << " ";
    for (int j = 0; j < length; j++) {
        out << X[0][j] << " ";
    }
    out << std::endl;
    for (long long unsigned i = 0; i < p; i++) {
        // X[(i + 1) % devid] = new double[length];
        t_i = a + h * i;
        for (int j = 0; j < length; j++) {
            k[0][j] = h * f(t_i, X[i % devid])[j];
        }
        for (int j = 0; j < length; j++) {
            tmp[j] = X[i % devid][j] + k[0][j] / (double) 2.0;
        }
        for (int j = 0; j < length; j++) {
            k[1][j] = h * f(t_i + h / (double) 2.0, tmp)[j];
        }
        for (int j = 0; j < length; j++) {
            tmp[j] = X[i % devid][j] + k[1][j] / (double) 2.0;
        }
        for (int j = 0; j < length; j++) {
            k[2][j] = h * f(t_i + h / (double) 2.0, tmp)[j];
        }
        for (int j = 0; j < length; j++) {
            tmp[j] = X[i % devid][j] + k[2][j];
        }
        for (int j = 0; j < length; j++) {
            k[3][j] = h * f(t_i + h, tmp)[j];
        }
        
        for (int j = 0; j < length; j++) {
            X[(i + 1) % devid][j] = X[i % devid][j] + (k[0][j] + (double) 2.0 * (k[1][j] + k[2][j]) + k[3][j]) / (double) 6.0;
        }
        t_i += h;
        out << t_i << " ";
        for (int j = 0; j < length; j++) {
            out << X[(i + 1) % devid][j] << " ";
        }
        out << std::endl;
    }
    for (long long unsigned i = 0; i < devid; i++) {
        delete[] X[i];
    }
    out.close();
    delete[] X;
    // return X;
}
