#ifndef __DEBUG_QUANTUM_H__
#define __DEBUG_QUANTUM_H__

#include "training.h"
#include <iostream>

class debug_quantum : public training {
public:
    bool train_quantum(network& model, unsigned int epoch, 
                      std::list<double>& input, std::list<double>& label, double delta) {
        
        std::cout << "=== DEBUG QUANTUM TRAINING ===" << std::endl;
        std::cout << "Initial input size: " << input.size() << std::endl;
        std::cout << "Label size: " << label.size() << std::endl;
        
        for (unsigned int step = 0; step < epoch; ++step) {
            std::cout << "--- Step " << step << " ---" << std::endl;
            std::cout << "Before set_input - Input size: " << input.size() << std::endl;
            
            model.set_input(input);
            std::cout << "After set_input - Input size: " << input.size() << std::endl;
            
            model.set_label(label);
            std::cout << "After set_label - Label size: " << label.size() << std::endl;
            
            model.predict();
            std::list<double> output = model.get_out_put();
            std::cout << "After predict - Output size: " << output.size() << std::endl;
            
            std::list<double> error = difference(output, label);
            std::cout << "Error size: " << error.size() << std::endl;
            
            model.set_error(error);
            model.train();
            
            std::cout << "After train - Input size: " << input.size() << std::endl;
            std::cout << "----------------" << std::endl;
            
            if (is_close(output, label, delta)) {
                std::cout << "SUCCESS at step " << step << std::endl;
                return true;
            }
            
            // Stop early after 5 steps to see the pattern
            if (step >= 5) {
                std::cout << "Stopping early after 5 steps for analysis..." << std::endl;
                break;
            }
        }
        
        return false;
    }
};

#endif