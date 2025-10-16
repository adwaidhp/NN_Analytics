#ifndef __ACTIVATION_H__
#define __ACTIVATION_H__

#include <cmath>
#include "global_enum.h"

class activation
{
public:
    double function(ACT_FUN f, double x)
    {
        switch(f)
        {
            case ACT_FUN::LINEAR: return x;
            case ACT_FUN::SIGMOID: return 1.0 / (1.0 + std::exp(-x));
            case ACT_FUN::RELU: return (x > 0) ? x : 0;
            case ACT_FUN::TANH_ACT: return std::tanh(x);
            case ACT_FUN::LEAKY_RELU: return (x > 0) ? x : 0.01 * x;
            default: return x;
        }
    }
};

#endif
