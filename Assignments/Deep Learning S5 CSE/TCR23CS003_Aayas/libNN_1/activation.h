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
				
					return  sigmoid (x);
				
				case ACT_FUN::relu:
				
					return  relu (x);
				
				case ACT_FUN::tanh:
				
					return  tanh_acti (x);
				
				case ACT_FUN::leaky_relu:
				
					return  leaky_relu (x);
					
				default:
				
					return x;
			}		
		}
	
		double sigmoid (double x)
		{
			return x;
		}

		double relu (double x)
		{
			if (x > 0.0) 
			{
				return x;
			}
		
			return 0;
		}

		double leaky_relu (double x)
		{
			if (x>0){
				return x;
			}
			return x*.01;
		}
		
		double tanh_acti(double x)
		{
			return std::tanh(x);
		}
};

#endif

