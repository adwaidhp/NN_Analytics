#ifndef __INPUT_H__
#define __INPUT_H__

#include <list> 
#include <iostream>
#include <cassert>

class input
{
	public:
		std::list<double> in;
		
		std::list<std::pair<bool, double>> w_out;
		
		input ()
		{
			// Initialize with some default values
			in.push_back(0.0);
			in.push_back(0.0);
		}
	
		input (std::list<double>& _in) : in (_in)
		{
		
		}
		
		void print () 
		{
			std::cout << "Input: [";
		
			for (auto field : in) 
			{
				printf ("%f ", field);
			}
		
			std::cout << "]" <<std::endl;
		}
		
		void set_input (std::list<double>& input)
		{
			// 🌟 FIXED: Handle size mismatch by resizing
			if (in.size() != input.size()) {
				std::cout << "Resizing input from " << in.size() << " to " << input.size() << std::endl;
				in.clear();
				in = input; // Just copy the entire list
			} else {
				// Original behavior if sizes match
				auto it_in = in.begin ();
				auto it_input = input.begin ();
				
				while (it_in != in.end ())
				{
					*it_in = *it_input;
					++it_in;
					++it_input;
				}
			}
		}
};

#endif