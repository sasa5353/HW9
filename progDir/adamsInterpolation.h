//
// Created by alex on 23.03.2020.
//

#ifndef TASK9_ADAMSINTERPOLATION_H
#define TASK9_ADAMSINTERPOLATION_H

#include "adamsExtrapolation.h"
#include "quadGauss.h"
#include "rungeKuttas.h"
#include "newtonsMethod.h"

void adamsInterpolation(std::string);
double *funcForAdams(double *);

#endif //TASK9_ADAMSINTERPOLATION_H
