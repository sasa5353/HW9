//
// Created by alex on 11.03.2020.
//

#include "Bernoulli.h"
double findRoot(Polynomial &polynomial) {
    if (polynomial.getDeg() == 1) {
        double a, b;
        a = polynomial.getKoef(1);
        b = polynomial.getKoef(0);
        return (-b) / (a);
    }
    if (polynomial.getDeg() == 2) {
        double a, b, c;
        a = polynomial.getKoef(2);
        b = polynomial.getKoef(1);
        c = polynomial.getKoef(0);
        return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    }
    double a[polynomial.getDeg()];
    for (unsigned int i = 0; i <= polynomial.getDeg(); i++) {
        a[i] = std::rand() % 10 + 5;
    }
    
    double *c = new double[2];
    List ans(c, c + 2);
    List list(a, a + polynomial.getDeg());
    
    for (int x = 0;
         ((x < 15) || fabs(ans.getFirst()->getValue() - ans.getLast()->getValue()) > (double)1.0e-15) && (x < 1000); x++) {
        double tmp = (double)0.0;
        ListElement *p = list.getLast();
        for (unsigned int i = 0; i < polynomial.getDeg(); i++) {
            tmp -= polynomial.getKoef(i) * p->getValue();
            p = p->getNext();
        }
        tmp /= polynomial.getKoef(polynomial.getDeg());
        
        ans.add(tmp / list.getFirst()->getValue());
        list.add(tmp);
    }
    delete[] c;
    
    return ans.getFirst()->getValue();
}

Polynomial monomial(double root) {
    double tmp[2] = {-root, (double)1.0};
    Polynomial polynomial(1, tmp);
    return polynomial;
}

Polynomial devByRoot(Polynomial &polynomial) {
    Polynomial multiplier = monomial(findRoot(polynomial));
    polynomial /= multiplier;
    return polynomial;
}

double *findRootsArray(Polynomial polynomial) {
    // Polynomial pol = polynomial;
    double *rootsArray = new double[polynomial.getDeg()];
    for (int i = 0; polynomial.getDeg(); i++) {
        rootsArray[i] = findRoot(polynomial);
        polynomial = devByRoot(polynomial);
    }
    
    return rootsArray;
}
