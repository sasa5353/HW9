//
// Created by alex on 10.03.2020.
//

#include "Polynomial.h"

Polynomial::Polynomial() {
    deg = 0;
    koef = new double[deg + 1];
    koef[0] = (double)0.0;
}

Polynomial::Polynomial(unsigned int new_deg, double *new_koef) {
    deg = 0;
    for (unsigned int i = 0; i <= new_deg; i++)
        if (new_koef[i] != 0) deg = i;
    koef = new double[deg + 1];
    for (unsigned int i = 0; i <= deg; i++)
        koef[i] = new_koef[i];
}

Polynomial::Polynomial(const Polynomial &f) {
    deg = f.deg;
    koef = new double[deg + 1];
    for (unsigned int i = 0; i <= deg; i++)
        koef[i] = f.koef[i];
}

Polynomial::~Polynomial() {
    delete[] koef;
}

unsigned int Polynomial::getDeg() {
    return deg;
}

double Polynomial::getKoef(unsigned int i) {
    if (i <= deg)
        return koef[i];
    else
        return (double)0.0;
}

Polynomial Polynomial::operator+(const Polynomial &t) {
    unsigned int i;
    Polynomial result;
    
    if (deg >= t.deg) {
        result = Polynomial(deg, koef);
        for (i = 0; i <= t.deg; i++)
            result.koef[i] = result.koef[i] + t.koef[i];
    } else {
        result = Polynomial(t.deg, t.koef);
        for (i = 0; i <= deg; i++)
            result.koef[i] = result.koef[i] + koef[i];
    }
    result.correctDeg();
    return result;
}

Polynomial operator-(const Polynomial &t) {
    Polynomial result;
    double new_koef[t.deg + 1];
    for (unsigned int i = 0; i <= t.deg; i++) {
        new_koef[i] = -t.koef[i];
    }
    result = Polynomial(t.deg, new_koef);
    return result;
}

Polynomial operator-(Polynomial &t1, Polynomial &t2) {
    Polynomial result;
    result = t1 + (double)-1.0 * t2;
    result.correctDeg();
    return result;
}

Polynomial operator-=(Polynomial &t1, Polynomial &t2) {
    t1 = t1 - t2;
    t1.correctDeg();
    return t1;
}

Polynomial operator+=(Polynomial &t1, Polynomial &t2) {
    t1 = t1 + t2;
    t1.correctDeg();
    return t1;
}

Polynomial Polynomial::operator=(const Polynomial &t) {
    deg = t.deg;
    delete[] koef;
    koef = new double[deg + 1];
    for (unsigned int i = 0; i <= deg; i++)
        koef[i] = t.koef[i];
    return *this;
}


Polynomial operator*(double K, Polynomial &t) {
    return multConst(K, t);
}

Polynomial operator*(Polynomial &t, double K) {
    return multConst(K, t);
}

Polynomial operator*(Polynomial &t1, Polynomial &t2) {
    return multPolynomial(t1, t2);
}

Polynomial multPolynomial(Polynomial &t1, Polynomial &t2) {
    if (!t1.deg || !t2.deg) {
        Polynomial result;
        return result;
    }
    unsigned int new_deg = t1.deg + t2.deg;
    double new_koef[new_deg + 1];
    for (unsigned int i = 0; i <= new_deg; i++) {
        new_koef[i] = (double) 0.0;
        for (unsigned int j = 0; j <= i; j++) {
            new_koef[i] += t1.getKoef(j) * t2.getKoef(i - j);
        }
    }
    Polynomial result(new_deg, new_koef);
    return result;
}

Polynomial multConst(double K, Polynomial &t) {
    if (K == 0) {
        Polynomial result;
        return result;
    } else {
        unsigned int deg = t.deg;
        double *tmp_koef = new double[deg + 1];
        for (unsigned int i = 0; i <= deg; i++)
            tmp_koef[i] = K * t.koef[i];
        Polynomial result(deg, tmp_koef);
        delete[] tmp_koef;
        return result;
    }
}

void Polynomial::correctDeg() {
    if (deg && koef[deg] == 0) {
        do {
            deg--;
        } while (deg && koef[deg] == 0);
    }
}

Polynomial operator/(Polynomial &dividend, Polynomial &divider) {
    
    Polynomial tmp = dividend;
    Polynomial tmp2;
    Polynomial mono[tmp.deg + 1];
    int index;
    for (index = 0; tmp.deg > divider.deg; index++) {
        int k = tmp.deg - divider.deg;
        double temp[k + 1];
        std::fill(temp, temp + k + 1, (double)0.0);
        temp[k] = tmp.koef[tmp.deg] / divider.koef[divider.deg];
        mono[index] = Polynomial(k, temp);
        
        tmp2 = mono[index] * divider;
        tmp -= tmp2;
        tmp.correctDeg();
    }
    if (tmp.deg == divider.deg) {
        double koef[1];
        koef[0] = tmp.koef[tmp.deg] / divider.koef[divider.deg];
        mono[index] = Polynomial((unsigned int) 0, koef);
    }
    
    tmp = Polynomial();
    for (int i = 0; i <= index; i++) tmp += mono[i];
    
    tmp.correctDeg();
    
    return tmp;
    
}

Polynomial operator/=(Polynomial &t1, Polynomial &t2) {
    t1 = t1 / t2;
    return t1;
}

Polynomial operator*=(Polynomial &t1, Polynomial &t2) {
    t1 = t1 * t2;
    return t1;
}

Polynomial operator%(Polynomial &t1, Polynomial &t2) {
    Polynomial tmp = t1 / t2;
    Polynomial tmp2 = tmp * t2;
    Polynomial tmp3 = t1 - tmp2;
    tmp3.correctDeg();
    
    return tmp3;
}
