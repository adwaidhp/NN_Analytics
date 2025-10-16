#ifndef __DATA_SET_H__
#define __DATA_SET_H__

#include <list> 
#include <cstdlib> 
#include <iostream>
#include <chrono>
#include <random>

class data_set
{
	public:

		data_set () 
		{			
		
		}
	
		double get_val (const double lower_bound, const double upper_bound) 
		{    	
		    	static std::random_device rd;
		    	static std::mt19937 gen(rd());
		    	std::uniform_real_distribution<> dis(lower_bound, upper_bound);
		    	
		    	return dis(gen);
		}


		std::list<double> get_list (const unsigned int size, const double lower_bound, const double upper_bound) 
		{
		    	std::list<double> _list;
		    	
		    	for (unsigned int index = 0; index < size; index++)
		    	{
		    		_list.push_back (get_val(lower_bound, upper_bound));	
		    	}
		    	
		    	return _list;
		}
};

#endif
