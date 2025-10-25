#ifndef __MODEL_H__
#define __MODEL_H__

#include "network.h"

class model
{
	public:
		network _nn = network ();
	
		model ()
		{
			
		}
		
		void set ()
		{
			std::list<std::list<std::pair<ACT_FUN, double>>> node_list;
			
			// --- PARAMETER UPDATE 1: Change Activation Functions ---
			// Layer 0: Tanh, Bias 2.0 (Changed from leaky_relu, 4.0)
			// Layer 1: Tanh, Biases 1.0, 0.5, 1.0 (Changed from leaky_relu, 5.0, 2.0, 4.0)
			// Layer 2 (Output): Sigmoid, Bias 1.5 (Changed from leaky_relu, 3.0)
			node_list = {{{ACT_FUN::tanh, 2.0}}, 
                         {{ACT_FUN::tanh, 1.0}, {ACT_FUN::tanh, 0.5}, {ACT_FUN::tanh, 1.0}}, 
                         {{ACT_FUN::sigmoid, 1.5}}};
			
			_nn.initialize (node_list);		
			
			// --- PARAMETER UPDATE 2: Increase Learning Rate Significantly ---
			_nn.set_learning_rate (0.001); // Increased from 0.0000000002


			// --- INPUT CONNECTIONS (ip_to_nn) ---
			// i1 weight changed from 1.0 to 0.5 and made trainable (true)
			ip_to_nn i1 = {0, 0, 0, 0.5, true}; 
			
			// i2 weight changed from -1.0 to -0.8
			ip_to_nn i2 = {0, 0, 0, -0.8, false};
			
		
			_nn.add (i1);
			
			_nn.add (i2);
			

			// --- INTER-NODE CONNECTIONS (nn_to_nn) ---
			// L0 to L1 connections: n0n10 weight changed to 0.2 and made trainable (true)
			nn_to_nn n0n10 = {0, 0, 0, 1, 0, 0, 0.2, true};
			
			nn_to_nn n0n11 = {0, 0, 0, 1, 1, 0, 1.0, false};
			
			nn_to_nn n0n12 = {0, 0, 0, 1, 2, 0, 1.0, false};
			
			// L1 to L2 connections: Recurrence removed (true -> false) and made trainable (true)
			nn_to_nn n10n20 = {1, 0, 0, 2, 0, 0, 0.75, true}; // Weight 0.75, non-recurrent
			
			nn_to_nn n11n20 = {1, 1, 0, 2, 0, 0, 0.75, true}; // Weight 0.75, non-recurrent
			
			nn_to_nn n12n20 = {1, 2, 0, 2, 0, 0, 0.75, true}; // Weight 0.75, non-recurrent
			
			// Intra-layer connections: n10n10 removed (commented out)
			// nn_to_nn n10n10 = {1, 0, 0, 1, 0, 0, 1.0, false}; 
			
			// n12n11 weight changed to 0.1
			nn_to_nn n12n11 = {1, 2, 0, 1, 1, 0, 0.1, false};
		
		
			_nn.add (n0n10);
			
			_nn.add (n0n11);
			
			_nn.add (n0n12);
			
			_nn.add (n10n20);
			
			_nn.add (n11n20);
			
			_nn.add (n12n20);
			
			// Removed _nn.add(n10n10);
			
			_nn.add (n12n11);
		
		
			// --- OUTPUT CONNECTION (nn_to_op) ---
			// Output weight changed to 1.2
			nn_to_op o1 = {2, 0, 0, 1.2, false}; 

			_nn.add (o1);
		}
};

#endif