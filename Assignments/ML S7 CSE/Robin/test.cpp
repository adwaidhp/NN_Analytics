#include <iostream>
#include <chrono>
#include <list> 
#include <random>

using namespace std;

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



int main()
{ 
 	// Test data for y = 2x + 1
 	std::cout << "Generating test data for y = 2x + 1:" << std::endl;
 	
 	for (double x = -5.0; x <= 5.0; x += 1.0) {
 		double y = 2*x + 1;
 		std::cout << "x = " << x << ", y = " << y << std::endl;
 	}
 	
 	std::cout << "\nRandom test data:" << std::endl;
 	
 	std::list<double> ip_list = get_list (3, -10.0, 10.0);
 
 	std::list<double> op_list = get_list (3, -10.0, 10.0);
 
 	std::cout << "Input: [";
 	for (auto item: ip_list)
 	{
 		std::cout << item << " ";
 	}
 	std::cout << "]" << std::endl;
  
 	std::cout << "Output: [";
 	for (auto item: op_list)
 	{
 		std::cout << item << " ";
 	}
 	std::cout << "]" << std::endl;
 
    	return 0;
}


/*
#include <list> 
#include <iostream>

	int main ()
	{
	
		std::list<double> in = {1, 2, 3, 4};

		std::list<double*> out;
		
		out.push_back (&(in.front()));

		auto it = in.begin();
		std::advance(it, 1);
		out.push_back (&(*it));
		
		std::advance(it, 1);
		out.push_back (&(*it));
		
		std::advance(it, 1);
		out.push_back (&(*it));
						
		for (auto field : out)
		{
			std::cout << (*field) <<std::endl;
		}

		// Update values
		auto it2 = in.begin();
		*it2 = 10;
		std::advance(it2, 1);
		*it2 = 11;
		std::advance(it2, 1);
		*it2 = 12;
		std::advance(it2, 1);
		*it2 = 13;

		std::cout << "After update:" << std::endl;
		for (auto field : out)
		{
			std::cout << (*field) <<std::endl;
		}
		return 0;
	}	
*/
