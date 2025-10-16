#ifndef __TRAINING_H__
#define __TRAINING_H__

#include "data_set.h"
#include "network.h"

class training
{
	public:
		training ()
		{
		
		}
	
		bool is_close (std::list<double> out_put, std::list<double> label, double delta)
		{
			assert (out_put.size () == label.size ());
			
			auto it_label = label.begin ();
			
			auto it_out_put = out_put.begin ();
			
			while (it_out_put != out_put.end ())
			{
				double diff = fabs(*it_out_put - *it_label);
				if (diff > delta)   
				{
					return false;
				}
				
				it_label++;
				
				it_out_put++;
			}
			
			return true;
		}

		std::list<double> difference (std::list<double> out_put, std::list<double>& label)
		{
			assert (out_put.size () == label.size ());
			
			std::list<double> result;
			
			auto it_label = label.begin ();
			
			auto it_out_put = out_put.begin ();
			
			while (it_out_put != out_put.end ())
			{
				result.push_back (*it_label - *it_out_put);
			
				it_label++;
				
				it_out_put++;
			}
			
			return result;
		}	

		bool train_single (network& model, std::list<double>& input, std::list<double>& label, double delta)
		{
			model.set_input (input);
			model.set_label (label);
				
			model.input::print ();
	
			unsigned int step = 0;
			const unsigned int max_steps = 10000;
		
			while (!is_close (model.get_out_put (), label, delta))
			{	
				if (step >= max_steps) 
				{
					std::cout << "Max steps reached: " << step << std::endl;
					model.input::print ();
					model.label::print ();
					model.error::print ();
					return false;
				}
			
				model.predict ();
				
				std::list<double> error = difference (model.get_out_put (), label);
				
				model.set_error (error);
				
				model.train ();
				
				++step;
				
				// Print progress every 100 steps
				if (step % 100 == 0) {
					std::cout << "Step " << step << ": ";
					model.output::print();
				}
			}
			
			std::cout << "Converged in " << step << " steps" << std::endl;
			model.input::print ();
			model.label::print ();
			model.output::print();
			model.print_weight();
			
			return true;
		}
};

#endif
