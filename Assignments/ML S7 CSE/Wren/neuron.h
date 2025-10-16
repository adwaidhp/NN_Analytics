#ifndef __NEURON_H__
#define __NEURON_H__

#include <string>
#include <list> 
#include <assert.h> 
#include <cmath>

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
		
			double result = 0.0;
			
			auto it_in = n_id->in.begin (); 
			
			auto it_w_in = n_id->w_in.begin (); 

			while (it_in != n_id->in.end ()) 
			{
				result += (**it_in) * (**it_w_in);
				
				++it_in;
			
				++it_w_in;
			}

			n_id->out = function (n_id->f, (result + n_id->b));
		}
			
		void backward (std::list<node>::iterator n_id)
		{
			if (n_id->error.empty()) return;
			
			double acc_err = 0.0;
			
			auto e_id = n_id->error.begin ();
			auto w_id = n_id->w_out.begin ();
			
			// Accumulate error from outputs
			while (e_id != n_id->error.end () && w_id != n_id->w_out.end ())
			{
				if (**e_id != 0.0)
				{	
					// Simple gradient: error * derivative
					double gradient = **e_id * loss(n_id->f, n_id->out);
					
					if (w_id->first) // if weight is trainable
					{
						// Update weights connected to this neuron
						auto it_in = n_id->in.begin();
						auto it_w_in = n_id->w_in.begin();
						
						while (it_in != n_id->in.end() && it_w_in != n_id->w_in.end())
						{
							**it_w_in += learning_rate * gradient * (**it_in);
							++it_in;
							++it_w_in;
						}
					}
					
					acc_err += gradient * w_id->second;
				}
					
				++e_id;
				++w_id;
			}
			
			// Update bias
			double bias_gradient = acc_err * loss(n_id->f, n_id->out);
			n_id->b += learning_rate * bias_gradient;
			
			n_id->delta = acc_err;
		}
};

#endif
