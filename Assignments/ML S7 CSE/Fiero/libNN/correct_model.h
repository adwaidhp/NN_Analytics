#ifndef __CORRECT_MODEL_H__
#define __CORRECT_MODEL_H__

#include "network.h"

class correct_model
{
	public:
		network _nn = network ();
	
		correct_model ()
		{
			
		}
		
		void set ()
		{
			std::list<std::list<std::pair<ACT_FUN, double>>> node_list;
			
			// 🌟 SIMPLE ARCHITECTURE: 2 inputs → 2 hidden → 1 output
			node_list = {
				{{ACT_FUN::leaky_relu, 2.0}},  // Layer 0: 2 inputs
				{
					{ACT_FUN::resonant_func, 3.0},  // Layer 1: 2 hidden (resonant!)
					{ACT_FUN::resonant_func, 3.0}
				}, 
				{{ACT_FUN::leaky_relu, 1.0}}   // Layer 2: 1 output
			};
			
			_nn.initialize (node_list);		
			_nn.set_learning_rate(0.02); 

			// Initialize 2 inputs
			_nn.in.clear();
			_nn.in.push_back(0.0);
			_nn.in.push_back(0.0);

			// 🌟 CORRECT CONNECTIONS - USING YOUR ORIGINAL SYNTAX
			
			// Input to Hidden connections
			// Input 0 → Hidden 0
			ip_to_nn i1 = {0, 0, 0, 1.0, false};
			_nn.add (i1);
			
			// Input 0 → Hidden 1  
			ip_to_nn i2 = {0, 0, 0, 1.0, false};
			_nn.add (i2);
			
			// Input 1 → Hidden 0
			ip_to_nn i3 = {0, 0, 0, 1.0, false};
			_nn.add (i3);
			
			// Input 1 → Hidden 1
			ip_to_nn i4 = {0, 0, 0, 1.0, false};
			_nn.add (i4);
			
			// Hidden to Output connections  
			// Hidden 0 → Output 0
			nn_to_op h1o = {1, 0, 0, 1.0, false};
			_nn.add (h1o);
			
			// Hidden 1 → Output 0
			nn_to_op h2o = {1, 1, 0, 1.0, false};
			_nn.add (h2o);
			
			std::cout << "✅ CORRECT MODEL INITIALIZED!" << std::endl;
			std::cout << "Architecture: 2 inputs → 2 resonant → 1 output" << std::endl;
			std::cout << "Using your original connection syntax" << std::endl;
		}
};

#endif