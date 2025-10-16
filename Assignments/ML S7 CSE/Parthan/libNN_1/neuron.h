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
    // 1) compute delta (standard backprop)
    double delta = 0.0;

    if (n_id->w_out.empty())
    {
        // output node: read the first error pointer (expected label - output)
        double out_err = 0.0;
        if (!n_id->error.empty() && n_id->error.front() != nullptr)
            out_err = *(n_id->error.front());

        double deriv = compute_derivative(n_id->f, n_id->out);
        delta = out_err * deriv;
    }
    else
    {
        // hidden node: accumulate downstream deltas * downstream weights
        double acc = 0.0;
        auto e_it = n_id->error.begin();
        auto w_it = n_id->w_out.begin();
        while (e_it != n_id->error.end() && w_it != n_id->w_out.end())
        {
            if (*e_it != nullptr)
                acc += (**e_it) * (w_it->second);
            ++e_it;
            ++w_it;
        }
        double deriv = compute_derivative(n_id->f, n_id->out);
        delta = acc * deriv;
    }

    // 2) clip delta to avoid huge gradients
    const double MAX_DELTA = 1e2;
    if (delta > MAX_DELTA) delta = MAX_DELTA;
    if (delta < -MAX_DELTA) delta = -MAX_DELTA;

    // 3) update input weights: w += lr * delta * input
    auto in_it = n_id->in.begin();
    auto win_it = n_id->w_in.begin();
    while (in_it != n_id->in.end() && win_it != n_id->w_in.end())
    {
        if (*in_it != nullptr && *win_it != nullptr)
        {
            double input_val = **in_it;
            double *wptr = *win_it;
            double update = learning_rate * delta * input_val;

            // clip each update
            const double MAX_UPDATE = 1e-1;
            if (update > MAX_UPDATE) update = MAX_UPDATE;
            if (update < -MAX_UPDATE) update = -MAX_UPDATE;

            *wptr += update;

            // if weight becomes non-finite, reset to a small finite number and warn
            if (!std::isfinite(*wptr))
            {
                std::cerr << "Numeric error: weight became non-finite; resetting small.\n";
                *wptr = (update >= 0.0) ? MAX_UPDATE : -MAX_UPDATE;
            }
        }
        ++in_it;
        ++win_it;
    }

    // 4) update bias with clipping
    double bias_update = learning_rate * delta;
    const double MAX_BIAS_UPDATE = 1e-1;
    if (bias_update > MAX_BIAS_UPDATE) bias_update = MAX_BIAS_UPDATE;
    if (bias_update < -MAX_BIAS_UPDATE) bias_update = -MAX_BIAS_UPDATE;

    n_id->b += bias_update;
    if (!std::isfinite(n_id->b))
    {
        std::cerr << "Numeric error: bias became non-finite. Resetting to 0.\n";
        n_id->b = 0.0;
    }

    // 5) store delta for upstream use
    n_id->delta = delta;
}

};

#endif




