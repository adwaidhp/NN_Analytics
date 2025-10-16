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
			// Simple model: 1 input -> 1 output with linear activation
			std::list<std::list<std::pair<ACT_FUN, double>>> node_list;
			
			// Single neuron with linear activation and bias initialized to 0
			node_list = {{{ACT_FUN::linear, 0.0}}};
			
			_nn.initialize (node_list);		
			
			// Higher learning rate for faster convergence
			_nn.set_learning_rate (0.01);

			// Connect input to the single neuron
			ip_to_nn i1 = {0, 0, 0, 1.0, true};  // trainable weight
			
			_nn.add (i1);
			
			// Connect neuron to output
			nn_to_op o1 = {0, 0, 0, 1.0, false};

			_nn.add (o1);
		}
};

#endif
