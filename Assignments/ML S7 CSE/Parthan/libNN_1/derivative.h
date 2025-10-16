#ifndef __DERIVATIVE_H__
#define __DERIVATIVE_H__

#include <cmath>
#include "global_enum.h"

class derivative 
{
public:
    // compute_derivative expects post-activation value (y) for sigmoid/tanh.
    inline double compute_derivative(ACT_FUN fun, double y)
    {
        switch (fun)
        {
            case ACT_FUN::sigmoid:     return y * (1.0 - y);
            case ACT_FUN::relu:        return (y > 0.0) ? 1.0 : 0.0;
            case ACT_FUN::leaky_relu:  return (y > 0.0) ? 1.0 : 0.01;
            case ACT_FUN::tanh_act:        return 1.0 - (y * y); // y = tanh(x)
            case ACT_FUN::linear:      return 1.0;
            default:                   return 1.0;
        }
    }

    // You can remove or ignore the "loss" member below if it's unused.
    inline double loss (ACT_FUN /*id*/, double x)
    {
        // placeholder if you want to compute a special per-activation loss contribution
        return x;
    }
};

#endif
