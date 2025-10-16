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
	
		double get_val (const unsigned int seed, const double lower_bound, const double upper_bound, const long max_rand) 
		{    	
		    	std::srand (seed);
		    	double random_val = static_cast<double>(std::rand()) / RAND_MAX;
		   	return lower_bound + (upper_bound - lower_bound) * random_val;
		}


		std::list<double> get_list (const unsigned int size, const double lower_bound, const double upper_bound, const long max_rand) 
		{
		    	std::list<double> _list;
		    	
		    	auto start = std::chrono::high_resolution_clock::now();
		    	
		    	for (unsigned int index = 0; index < size; index++)
		    	{
		    		auto finish = std::chrono::high_resolution_clock::now();
		    		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start);
		    		_list.push_back (get_val (duration.count(), lower_bound, upper_bound, max_rand));	
		    	}
		    	
		    	return _list;
		}
};

#endif