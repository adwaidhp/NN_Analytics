#ifndef _ACTIVATION_H_
#define _ACTIVATION_H_

#include "global_enum.h"
#include <cmath>

class activation {
public:
    double function(ACT_FUN id, double x) {
        switch(id) {
            case sigmoid: return sigmoid(x);
            case relu: return relu(x);
            case tanh_act: return tanh_act(x);
            case leaky_relu: return leaky_relu(x);
            default: return x;
        }
    }

    double sigmoid(double x) { return 1.0 / (1.0 + std::exp(-x)); }
    double relu(double x) { return (x > 0 ? x : 0); }
    double leaky_relu(double x) { return (x > 0 ? x : 0.01 * x); }
    double tanh_act(double x) { return std::tanh(x); }
};

#endif