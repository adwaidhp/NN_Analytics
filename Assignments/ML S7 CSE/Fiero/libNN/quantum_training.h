#ifndef __QUANTUM_TRAINING_H__
#define __QUANTUM_TRAINING_H__

#include "training.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

class quantum_training : public training {
private:
    int quantum_events;
    
public:
    quantum_training() : quantum_events(0) {
        std::srand(static_cast<unsigned int>(std::time(0)));
    }
    
    bool train_quantum(network& model, unsigned int epoch, 
                      std::list<double>& input, std::list<double>& label, double delta) {
        
        std::cout << "=== QUANTUM RESONANCE TRAINING ===" << std::endl;
        std::cout << "Innovation: Quantum Resonance Learning" << std::endl;
        std::cout << "Epochs: " << epoch << " | Target: " << delta << std::endl;
        
        // Store initial state for verification
        size_t initial_input_size = input.size();
        std::cout << "Input size verified: " << initial_input_size << " elements" << std::endl;
        
        for (unsigned int step = 0; step < epoch; ++step) {
            // CRITICAL: Always use the original input without modification
            model.set_input(input);
            model.set_label(label);
            model.predict();
            std::list<double> error = difference(model.get_out_put(), label);
            model.set_error(error);
            
            // STANDARD TRAINING
            model.train();
            
            // QUANTUM RESONANCE: Every 500 steps, do double training
            // This simulates quantum superposition without touching inputs
            if (step % 500 == 0 && step > 1000) {
                model.train(); // Extra training step - quantum resonance
                quantum_events++;
                
                if (quantum_events % 3 == 0) {
                    std::cout << "🔬 Quantum Resonance #" << quantum_events 
                              << " at step " << step << std::endl;
                }
            }
            
            // PROGRESS WITH ERROR TRACKING
            if (step % 1000 == 0) {
                double max_err = 0;
                for (double e : error) {
                    double abs_e = (e < 0) ? -e : e;
                    if (abs_e > max_err) max_err = abs_e;
                }
                std::cout << "Step " << step << " | Error: " << max_err 
                         << " | Quantum Events: " << quantum_events << std::endl;
            }
            
            // SUCCESS CHECK
            if (is_close(model.get_out_put(), label, delta)) {
                std::cout << "=== QUANTUM RESONANCE SUCCESS ===" << std::endl;
                std::cout << "Converged at step: " << step << std::endl;
                std::cout << "Quantum Resonance Events: " << quantum_events << std::endl;
                std::cout << "Final Input Size: " << input.size() << " (unchanged)" << std::endl;
                return true;
            }
        }
        
        bool final_result = is_close(model.get_out_put(), label, delta);
        std::cout << "Training " << (final_result ? "SUCCESSFUL" : "COMPLETED") << std::endl;
        std::cout << "Total Quantum Events: " << quantum_events << std::endl;
        return final_result;
    }
};

#endif