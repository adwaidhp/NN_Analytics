#ifndef __ACTIVATION_H__
#define __ACTIVATION_H__

#include "global_enum.h"
#include <cmath>
#include <algorithm>

class activation 
{
public:
    activation() {}

    double function(ACT_FUN id, double x) 
    {
        switch (id)
        {
            case ACT_FUN::sigmoid:    return sigmoid(x);
            case ACT_FUN::relu:       return relu(x);
            case ACT_FUN::tanh_act:   return tanh_fn(x);
            case ACT_FUN::leaky_relu: return leaky_relu(x);
            default:                  return x;
        }
    }

    double sigmoid(double x)
    {
        // Clamp to avoid overflow
        x = std::clamp(x, -50.0, 50.0);
        return 1.0 / (1.0 + std::exp(-x));
    }

    double relu(double x) { return (x > 0.0) ? x : 0.0; }

    double leaky_relu(double x) { return (x > 0.0) ? x : 0.01 * x; }

    double tanh_fn(double x)
    {
        x = std::clamp(x, -50.0, 50.0);
        return std::tanh(x);
    }
};

#endif
