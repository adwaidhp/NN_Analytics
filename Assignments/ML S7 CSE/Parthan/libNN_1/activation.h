#ifndef __ACTIVATION_H__
#define __ACTIVATION_H__

#include <cmath>
#include "global_enum.h"

class activation 
{
	public:
	
		activation () { }

		// function dispatch for activation
		inline double function (ACT_FUN id, double x) 
		{
			switch (id)
			{
				case ACT_FUN::sigmoid:     return sigmoid (x);
				case ACT_FUN::relu:        return relu (x);
				case ACT_FUN::tanh_act:        return tanh_act (x);
				case ACT_FUN::leaky_relu:  return leaky_relu (x);
				case ACT_FUN::linear:      return x;
				default:                   return x;
			}		
		}
	
		inline double sigmoid (double x)
		{
			// numerically stable sigmoid
			if (x >= 0.0) {
				double z = std::exp(-x);
				return 1.0 / (1.0 + z);
			} else {
				double z = std::exp(x);
				return z / (1.0 + z);
			}
		}

		inline double relu (double x)
		{
			return (x > 0.0) ? x : 0.0;
		}

		inline double leaky_relu (double x)
		{
			return (x > 0.0) ? x : 0.01 * x;
		}
		
		inline double tanh_act (double x)
		{
			return std::tanh(x);
		}
};

#endif
