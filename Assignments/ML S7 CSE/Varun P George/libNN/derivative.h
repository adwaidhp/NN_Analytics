#ifndef __DERIVATIVE_H__
#define __DERIVATIVE_H__

#include <cmath>
#include "global_enum.h"

class derivative
{
public:
    double deriv(ACT_FUN f, double x)
    {
        switch(f)
        {
            case ACT_FUN::LINEAR: return 1.0;
            case ACT_FUN::SIGMOID: {
                double s = 1.0 / (1.0 + std::exp(-x));
                return s * (1.0 - s);
            }
            case ACT_FUN::RELU: return (x > 0) ? 1.0 : 0.0;
            case ACT_FUN::TANH_ACT: return 1.0 - std::tanh(x) * std::tanh(x);
            case ACT_FUN::LEAKY_RELU: return (x > 0) ? 1.0 : 0.01;
            default: return 1.0;
        }
    }
};

#endif
