#ifndef __ACTIVATION_H__
#define __ACTIVATION_H__


#include "global_enum.h"
#include <math.h>

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
				
					return  sigmoid (x);
				
				case ACT_FUN::relu:
				
					return  relu (x);
				
				case ACT_FUN::TanH:
				
					return  tanh (x);
				
				case ACT_FUN::leaky_relu:
				
					return  leaky_relu (x);
					
				default:
				
					return x;
			}		
		}
	
		double sigmoid (double x)
		{
			// Implementation: 1.0 / (1.0 + e^(-x))
				return 1.0 / (1.0 + exp(-x));
		}

		double relu (double x)
		{
			if (x > 0.0) 
			{
				return x;
			}
		
			return 0;
		}

		// Define the small constant alpha (common values are 0.01 or 0.1)
		const double ALPHA = 0.01; 

		double leaky_relu (double x)
		{
			if (x > 0.0)
			{
				return x;
			}
			
			// For x <= 0, return a small fraction of x
			return ALPHA * x;
		}
		
		double tanh (double x)
		{
			// The standard library (e.g., C/C++ <math.h>) provides a tanh() function, 
			// which is the most efficient way to implement it.
			// If you must use exp():
			double exp_plus_x = exp(x);
			double exp_minus_x = exp(-x);
			
			return (exp_plus_x - exp_minus_x) / (exp_plus_x + exp_minus_x);
		}
		};

#endif

