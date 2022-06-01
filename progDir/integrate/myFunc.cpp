//
// Created by alex on 20.03.2020.
//

#include "myFunc.h"

double funcA(double x, int j) {
    double ans = x;
    for (long long unsigned i = 1; i < n; i++){
        ans *= x + (double) i;
    }
    ans /= x + (double) j;
    return ans;
}

double funcB(double x, int j) {
    double ans = x - (double) 1.0;
    for (long long unsigned i = 0; i < n - 1; i++){
        ans *= x + (double) i;
    }
    ans /= x + (double) j;
    return ans;
}

double pow(double d, int j) {
    if (j == 0) {
        return 1.0;
    }
    return pow(d * d, j / 2) * (j % 2 ? d : 1);
}
