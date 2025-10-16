#include <iostream>
#include <list>
#include "model.h"
#include "quantum_training.h"  // Include the quantum header

int main() {
    model mdl;
    quantum_training trainer;  // Use quantum_training class
    
    std::list<double> _input;
    _input.push_back(-9927.00);
    _input.push_back(-9861.80);
    
    std::list<double> _label;
    _label.push_back(-9731.20);
    
    double delta = 0.00001;
    
    std::cout << "Starting Advanced Quantum Training..." << std::endl;
    bool result = trainer.train_quantum(mdl._nn, 15000, _input, _label, delta);
    
    if (result) {
        std::cout << "FINAL: QUANTUM TRAINING SUCCESS!" << std::endl;
    } else {
        std::cout << "FINAL: Training completed" << std::endl;
    }
    
    return 0;
}