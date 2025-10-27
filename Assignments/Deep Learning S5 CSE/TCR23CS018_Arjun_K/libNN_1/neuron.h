#ifndef __NEURON_H__
#define __NEURON_H__

#include <string>
#include <list> 
#include <assert.h> 

#include "output.h"
#include "input.h"
#include "error.h"
#include "label.h"
#include "structures.h"
#include "activation.h"
#include "derivative.h"


class neuron : public activation, public derivative
{
	public:	
		double learning_rate;
	
		bool in_forward;
		
		bool in_backward;
		
		neuron ()
		{
		
		}
		
		void forward (std::list<node>::iterator n_id) 
		{
			assert (n_id->w_in.size () == n_id->in.size ());
		
			double result = 0;
			
			auto it_in = n_id->in.begin (); 
			
			auto it_w_in = n_id->w_in.begin (); 

			while (it_in != n_id->in.end ()) 
			{
				result +=  (**it_in) * (**it_w_in);
				
				++it_in;
			
				++it_w_in;
			}

			n_id->out = function (n_id->f, (result + n_id->b));
		}
			
		void backward (std::list<node>::iterator n_id)
		{
			// n_id is node 'i'

			// 1. Calculate this node's delta (error term)
			// For hidden nodes: delta_i = (SUM_j (delta_j * w_ij)) * f'(net_i)
			// For output nodes: delta_i = (target_i - output_i) * f'(net_i)
			
			double weighted_error_sum = 0;
			
			auto e_id = n_id->error.begin(); // This is delta_j (from next layer) or (target - output)
			auto w_id = n_id->w_out.begin(); // This is w_ij (outgoing weight)
			
			// This loop calculates SUM_j (delta_j * w_ij)
			// For output nodes, e_id has one element (target-output) and w_id has one
			// element (weight=1.0, trainable=false), so sum = (target-output) * 1.0
			while (e_id != n_id->error.end () && w_id != n_id->w_out.end ())
			{
				weighted_error_sum += (**e_id) * (w_id->second); 
				++e_id;
				++w_id;
			}

			// Calculate f'(net_i). 
			// The derivative function is confusingly named 'loss' in derivative.h
			// It's implemented in terms of output 'x' (n_id->out), which is fine.
			double derivative_of_output = loss(n_id->f, n_id->out);
			
			// This is the final delta for this node (delta_i)
			n_id->delta = weighted_error_sum * derivative_of_output;

			
			// 2. Update this node's bias
			// delta_b = eta * delta_i
			n_id->b += (learning_rate * n_id->delta);

			
			// 3. Update all INCOMING weights (w_ki)
			// delta_w_ki = eta * delta_i * o_k
			// This is the part that was missing/incorrect in the original.
			
			auto it_w_in = n_id->w_in.begin(); // This is w_ki
			auto it_in = n_id->in.begin();     // This is o_k (output of previous node)
			
			while (it_w_in != n_id->w_in.end() && it_in != n_id->in.end())
			{
				// **it_w_in is a pointer to the weight value
				// **it_in is a pointer to the input value
				
				double input_output = **it_in; // This is o_k
				double gradient = n_id->delta * input_output; // This is delta_i * o_k
				
				// We assume the weight is trainable, which you set in model.h.
				// (A more robust design would check a trainable flag here)
				(**it_w_in) += (learning_rate * gradient);
				
				++it_w_in;
				++it_in;
			}
		}
};

#endif




