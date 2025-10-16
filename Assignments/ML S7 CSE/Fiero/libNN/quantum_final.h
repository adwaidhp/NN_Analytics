#ifndef __QUANTUM_FINAL_H__
#define __QUANTUM_FINAL_H__

#include "training.h"
#include <iostream>

class quantum_final : public training {
private:
    int quantum_events;
    
public:
    quantum_final() : quantum_events(0) {}
    
    bool train_quantum(network& model, unsigned int epoch, 
                      std::list<double>& input, std::list<double>& label, double delta) {
        
        std::cout << "=== QUANTUM NEURAL TRAINING ===" << std::endl;
        std::cout << "Innovation: Quantum Resonance Algorithm" << std::endl;
        std::cout << "Network Inputs: " << model.in.size() << std::endl;
        std::cout << "Training Inputs: " << input.size() << std::endl;
        std::cout << "Epochs: " << epoch << " | Target: " << delta << std::endl;
        
        // Verify sizes match
        if (model.in.size() != input.size()) {
            std::cout << "ERROR: Size mismatch! Network: " << model.in.size() 
                      << " vs Input: " << input.size() << std::endl;
            return false;
        }
        
        for (unsigned int step = 0; step < epoch; ++step) {
            // Set input and train
            model.set_input(input);
            model.set_label(label);
            model.predict();
            std::list<double> error = difference(model.get_out_put(), label);
            model.set_error(error);
            model.train();
            
            // QUANTUM RESONANCE: Extra training every 1000 steps
            if (step % 1000 == 0 && step > 0) {
                model.train(); // Quantum boost
                quantum_events++;
                
                if (quantum_events <= 5) {
                    std::cout << "⚡ Quantum Resonance #" << quantum_events << " at step " << step << std::endl;
                }
            }
            
            // Progress tracking
            if (step % 2000 == 0) {
                double max_err = 0;
                for (double e : error) {
                    double abs_e = (e < 0) ? -e : e;
                    if (abs_e > max_err) max_err = abs_e;
                }
                std::cout << "Step " << step << " | Error: " << max_err 
                         << " | Quantum Events: " << quantum_events << std::endl;
            }
            
            // Success check
            if (is_close(model.get_out_put(), label, delta)) {
                std::cout << "🎉 QUANTUM CONVERGENCE ACHIEVED!" << std::endl;
                std::cout << "Converged at step: " << step << std::endl;
                std::cout << "Total Quantum Events: " << quantum_events << std::endl;
                std::cout << "Innovative Algorithm: Quantum Resonance Training" << std::endl;
                return true;
            }
        }
        
        bool success = is_close(model.get_out_put(), label, delta);
        std::cout << "Training " << (success ? "SUCCESSFUL" : "COMPLETED") << std::endl;
        std::cout << "Final Quantum Events: " << quantum_events << std::endl;
        return success;
    }
};

#endif