#ifndef __DATA_SET_H__
#define __DATA_SET_H__

#include <list> 
#include <cstdlib> 
#include <iostream>
#include <ctime>  // Add this for time()

class data_set
{
	public:

		data_set () 
		{			
		
		}
	
		double get_val (const unsigned int seed, const double lower_bound, const double upper_bound, const long max_rand) 
		{    	
		    std::srand (seed);
		    return lower_bound + (upper_bound - lower_bound) * (rand() % max_rand) / max_rand;
		}


		std::list<double> get_list (const unsigned int size, const double lower_bound, const double upper_bound, const long max_rand) 
		{
		    std::list<double> _list;
		    
		    // FIXED: Use simple timestamp instead of chrono
		    unsigned int base_seed = static_cast<unsigned int>(time(0));
		    
		    for (unsigned int index = 0; index < size; index++)
		    {
		        // Use index + base_seed for different seeds
		        _list.push_back (get_val (base_seed + index, lower_bound, upper_bound, max_rand));	
		    }
		    
		    return _list;
		}
};

#endif