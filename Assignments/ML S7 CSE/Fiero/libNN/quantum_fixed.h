#ifndef __QUANTUM_FIXED_H__
#define __QUANTUM_FIXED_H__

#include "training.h"
#include <iostream>

class quantum_fixed : public training {
public:
    bool train_quantum(network& model, unsigned int epoch, 
                      std::list<double>& input, std::list<double>& label, double delta) {
        
        std::cout << "=== QUANTUM TRAINING (FIXED) ===" << std::endl;
        std::cout << "Input size: " << input.size() << std::endl;
        std::cout << "Network input size: " << model.in.size() << std::endl;
        std::cout << "Epochs: " << epoch << " | Target: " << delta << std::endl;
        
        // Verify sizes match
        if (input.size() != model.in.size()) {
            std::cout << "ERROR: Input size mismatch!" << std::endl;
            std::cout << "Expected: " << model.in.size() << " | Got: " << input.size() << std::endl;
            return false;
        }
        
        int quantum_events = 0;
        
        for (unsigned int step = 0; step < epoch; ++step) {
            // Set input (size should match now)
            model.set_input(input);
            model.set_label(label);
            model.predict();
            std::list<double> error = difference(model.get_out_put(), label);
            model.set_error(error);
            model.train();
            
            // Quantum effect: occasional double training
            if (step % 500 == 0 && step > 1000) {
                model.train(); // Extra quantum training step
                quantum_events++;
            }
            
            // Progress
            if (step % 1000 == 0) {
                double max_err = 0;
                for (double e : error) {
                    double abs_e = (e < 0) ? -e : e;
                    if (abs_e > max_err) max_err = abs_e;
                }
                std::cout << "Step " << step << " | Error: " << max_err 
                         << " | Quantum: " << quantum_events << std::endl;
            }
            
            if (is_close(model.get_out_put(), label, delta)) {
                std::cout << "QUANTUM SUCCESS at step " << step << std::endl;
                return true;
            }
        }
        
        return is_close(model.get_out_put(), label, delta);
    }
};

#endif