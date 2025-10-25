#ifndef __ACTIVATION_H__
#define __ACTIVATION_H__

#include <cmath> // Required for std::exp and std::tanh
#include "global_enum.h"

class activation 
{
public:

    activation() {}

    /**
     * @brief Applies the selected activation function to the weighted sum (z).
     * @param id The ACT_FUN enum identifying the function.
     * @param x The input value (weighted sum + bias).
     * @return The activated output value.
     */
    double function (ACT_FUN id, double x) 
    {
        switch (id)
        {
            case ACT_FUN::sigmoid:
                return sigmoid (x);
            
            case ACT_FUN::relu:
                return relu (x);
            
            case ACT_FUN::tanh:
                return tanh (x);
            
            case ACT_FUN::leaky_relu:
                return leaky_relu (x);
                
            default:
                // Defaulting to linear activation (identity) if ID is unknown
                return x;
        }		
    }

private:
    // Standard Sigmoid Function: 1 / (1 + e^-x)
    double sigmoid (double x)
    {
        return 1.0 / (1.0 + std::exp(-x));
    }

    // Standard ReLU Function: max(0, x)
    double relu (double x)
    {
        if (x > 0.0) 
        {
            return x;
        }
    
        return 0.0;
    }

    // Standard Leaky ReLU Function: x for x > 0, and 0.01x for x <= 0
    double leaky_relu (double x)
    {
        if (x > 0.0) 
        {
            return x;
        }
        
        // Use a small constant alpha (0.01) for the negative slope
        return 0.01 * x; 
    }
    
    // Standard Hyperbolic Tangent Function: (e^x - e^-x) / (e^x + e^-x)
    double tanh (double x)
    {
        // std::tanh(x) from cmath is the standard implementation
        return std::tanh(x); 
    }
};

#endif