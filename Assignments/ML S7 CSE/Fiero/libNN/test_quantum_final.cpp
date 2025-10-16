#include <iostream>
#include <list>
#include "model.h"
#include "quantum_final.h"

int main() {
    model mdl;
    
    // Initialize the model with network structure
    std::cout << "Initializing neural network..." << std::endl;
    mdl.set();
    
    std::cout << "Network initialized with " << mdl._nn.in.size() << " inputs" << std::endl;
    
    quantum_final trainer;
    
    // Training data - MUST match the network input size (4 inputs)
    std::list<double> _input;
    _input.push_back(-9927.00);   // Input 1
    _input.push_back(-9861.80);   // Input 2  
    _input.push_back(1.0);        // Input 3 (bias/constant)
    _input.push_back(0.5);        // Input 4 (additional feature)
    
    std::list<double> _label;
    _label.push_back(-9731.20);
    
    double delta = 0.00001;
    
    std::cout << "Training with " << _input.size() << " inputs" << std::endl;
    std::cout << "Starting Quantum Training..." << std::endl;
    bool result = trainer.train_quantum(mdl._nn, 15000, _input, _label, delta);
    
    if (result) {
        std::cout << "🎊 FINAL: QUANTUM TRAINING SUCCESSFUL! 🎊" << std::endl;
    } else {
        std::cout << "Training completed" << std::endl;
    }
    
    return 0;
}