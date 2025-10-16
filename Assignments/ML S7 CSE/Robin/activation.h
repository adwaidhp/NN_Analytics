#ifndef __ACTIVATION_H__
#define __ACTIVATION_H__

#include "global_enum.h"

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
					return 1.0 / (1.0 + exp(-x));
				
				case ACT_FUN::relu:
					if (x > 0.0) return x;
					return 0.0;
				
				case ACT_FUN::tanh_act:
                                        return tanh(x);
				
				case ACT_FUN::leaky_relu:
					if (x > 0.0) return x;
					return 0.01 * x;
				
				case ACT_FUN::linear:
				default:
					return x;
			}		
		}
};

#endif
