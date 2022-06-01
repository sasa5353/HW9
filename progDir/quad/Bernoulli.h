//
// Created by alex on 11.03.2020.
//

#ifndef UNTITLED_BERNOULLI_H
#define UNTITLED_BERNOULLI_H

#include <cstdlib>
#include <cmath>
#include "Polynomial.h"
#include "List.h"


double findRoot(Polynomial &polynomial);

Polynomial monomial(double);

Polynomial devByRoot(Polynomial &);

double *findRootsArray(Polynomial polynomial);

#endif //UNTITLED_BERNOULLI_H
