//
// Created by alex on 18.03.2020.
//

#include "Legendre.h"

Polynomial polynomialLegendre(int n) {
    Polynomial *leg = new Polynomial[n+1];
    double tmp[1] = {(double)1.0};
    Polynomial polynom(0, tmp);
    leg[0] = polynom;
    double newTmp[2] = {(double)0.0, (double)1.0};
    polynom = Polynomial(1, newTmp);
    leg[1] = polynom;
    for (int i = 2; i <= n; i++) {
        Polynomial polynomial;
        
        Polynomial prewPololLeg = leg[i - 1];
        Polynomial oldPololLeg = leg[i - 2];
        prewPololLeg = ((double) (2 * i - 1)) * prewPololLeg;
        Polynomial temp = polynomialLegendre(1);
        prewPololLeg *= temp;
        oldPololLeg = ((double) (i - 1)) * oldPololLeg;
        
        polynomial = (prewPololLeg - oldPololLeg);
        polynomial = polynomial * ((double)1.0 / (double) i);
        
        leg[i] = polynomial;
    }
    Polynomial polynomial(leg[n]);
    delete[] leg;
    return polynomial;
}

double *rootsLegendre(int n) {
    Polynomial pol = polynomialLegendre(n);
    
    double *ans = new double[n];
    int i = 0;
    if (n % 2) {
        ans[i] = (double)0.0;
        i++;
    }
    double *tmp = new double[n / 2 + 1];
    for (int j = 0; i <= n; j++, i += 2) {
        tmp[j] = pol.getKoef(i);
    }
    Polynomial newPol(n / 2, tmp);
    delete[] tmp;
    double *a = findRootsArray(newPol);
    for (int j = 0, i = n % 2; i < n; j++, i += 2) {
        ans[i] = sqrt(a[j]);
        ans[i + 1] = -ans[i];
    }
    delete[] a;
    
    return ans;
}
