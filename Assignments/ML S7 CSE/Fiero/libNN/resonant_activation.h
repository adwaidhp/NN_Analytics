#ifndef __RESONANT_ACTIVATION_H__
#define __RESONANT_ACTIVATION_H__

#include <cmath>

// 🌟 RESONANT ACTIVATION FUNCTION - LIKE QUANTUM WAVES!
inline double resonant(double x) {
    return exp(-0.5 * x * x) * sin(5.0 * x);
}

// 📈 DERIVATIVE FOR LEARNING
inline double resonant_derivative(double x) {
    double exp_part = exp(-0.5 * x * x);
    double term1 = (-1.0 * x * exp_part) * sin(5.0 * x);
    double term2 = exp_part * (5.0 * cos(5.0 * x));
    return term1 + term2;
}

#endif