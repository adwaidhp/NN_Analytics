#ifndef __ACTIVATION_H__
#define __ACTIVATION_H__

#include "global_enum.h"
#include <cmath>

class activation 
{
	public:
	
		activation ()
		{
		
		}
	
		double function (ACT_FUN id, double x) 
		{
			switch (id)
			{
				case ACT_FUN::sigmoid:
					return sigmoid (x);
				
				case ACT_FUN::tanh_func:
					return tanh_func (x);
				
				case ACT_FUN::relu:
					return relu (x);
				
				case ACT_FUN::leaky_relu:
					return leaky_relu (x);
					
				case ACT_FUN::linear:
					return linear(x);
					
				default:
					return x;
			}		
		}
	
		double sigmoid (double x)
		{
			return 1.0 / (1.0 + exp(-x));
		}

		double relu (double x)
		{
			if (x > 0.0) 
			{
				return x;
			}
			return 0.0;
		}

		double leaky_relu (double x)
		{
			if (x > 0.0) 
			{
				return x;
			}
			return 0.01 * x; // Proper leaky ReLU
		}
		
		double tanh_func (double x)
		{
			return std::tanh(x);
		}
		
		double linear (double x)
		{
			return x;  // Simple linear function
		}
};

#endif