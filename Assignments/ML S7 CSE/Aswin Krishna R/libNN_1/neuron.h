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
			
		void backward(std::list<node>::iterator n_id)
{
    assert(n_id->w_out.size() == n_id->error.size());
    
    double acc_err = 0;
    int valid_count = 0;
    
    auto e_id = n_id->error.begin();
    auto w_id = n_id->w_out.begin();
    
    // Calculate error for this neuron
    while (e_id != n_id->error.end() && w_id != n_id->w_out.end())
    {
        if (!std::isnan(**e_id) && !std::isinf(**e_id)) 
        {
            double weighted_error = **e_id * w_id->second;
            
            // Gradient clipping
            if (weighted_error > 1.0) weighted_error = 1.0;
            if (weighted_error < -1.0) weighted_error = -1.0;
            
            acc_err += weighted_error;
            valid_count++;
            
            // Update weights (backpropagate to previous layer)
            if (w_id->first && valid_count > 0) 
            {
                double derivative_val = loss(n_id->f, n_id->out);
                double weight_update = learning_rate * (**e_id) * derivative_val;
                
                // Clip weight updates
                if (weight_update > 0.1) weight_update = 0.1;
                if (weight_update < -0.1) weight_update = -0.1;
                
                w_id->second += weight_update;
                
                // Clip weights
                if (w_id->second > 5.0) w_id->second = 5.0;
                if (w_id->second < -5.0) w_id->second = -5.0;
            }
        }
        ++e_id;
        ++w_id;
    }
    
    if (valid_count > 0) 
    {
        // Apply activation function derivative
        double derivative_val = loss(n_id->f, n_id->out);
        acc_err = acc_err * derivative_val / valid_count;
        
        // Clip accumulated error
        if (acc_err > 1.0) acc_err = 1.0;
        if (acc_err < -1.0) acc_err = -1.0;
    }
    
    // Update bias
    double bias_update = learning_rate * acc_err;
    if (bias_update > 0.1) bias_update = 0.1;
    if (bias_update < -0.1) bias_update = -0.1;
    
    n_id->b += bias_update;
    
    // Clip bias
    if (n_id->b > 5.0) n_id->b = 5.0;
    if (n_id->b < -5.0) n_id->b = -5.0;
    
    n_id->delta = acc_err;
}
};

#endif