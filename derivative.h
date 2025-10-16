#ifndef __DERIVATIVE_H__
#define __DERIVATIVE_H__

#include "global_enum.h"
#include <cmath>

class derivative 
{
public:
    derivative () {}

    double loss (ACT_FUN id, double x) 
    {
        switch (id)
        {
            case ACT_FUN::sigmoid:
                return sigmoid(x);

            case ACT_FUN::relu:
                return relu(x);

            case ACT_FUN::tanh_act:
                return tanh_derivative(x); // ✅ fixed

            case ACT_FUN::leaky_relu:
                return leaky_relu(x);

            default:
                return x;
        }		
    }

    double sigmoid (double x)
    {
        return x * (1 - x);
    }

    double relu (double x)
    {
        return (x > 0.0) ? 1.0 : 0.0;
    }

    double leaky_relu (double x)
    {
        return (x > 0.0) ? 1.0 : 0.01;
    }

    double tanh_derivative (double x)
    {
        // If x is tanh(x), derivative = 1 - x^2
        return 1.0 - (x * x);
    }
};

#endif
