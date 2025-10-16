#ifndef __DERIVATIVE_H__
#define __DERIVATIVE_H__

#include "global_enum.h"
#include <cmath>

class derivative 
{
	public:
	
		derivative ()
		{
		
		}
	
		double loss (ACT_FUN id, double x) 
		{
			switch (id)
			{
				case ACT_FUN::sigmoid:
				{
					double s = 1.0 / (1.0 + exp(-x));
					return s * (1 - s);
				}
				
				case ACT_FUN::relu:
					return (x > 0.0) ? 1.0 : 0.0;
				
				case ACT_FUN::tanh_act:
				{
					double t = tanh(x);
					return 1 - t * t;
				}
				
				case ACT_FUN::leaky_relu:
					return (x > 0.0) ? 1.0 : 0.01;
				
				case ACT_FUN::linear:
				default:
					return 1.0;
			}		
		}
};

#endif
