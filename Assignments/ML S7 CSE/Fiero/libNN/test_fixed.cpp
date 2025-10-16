#include <iostream>
#include <list>
#include "model.h"
#include "quantum_fixed.h"

int main() {
    model mdl;
    quantum_fixed trainer;
    
    // FIRST: Check what size the model expects
    size_t expected_size = mdl._nn.in.size();
    std::cout << "Model expects " << expected_size << " input values" << std::endl;
    
    // Create input with the CORRECT size
    std::list<double> _input;
    if (expected_size == 1) {
        _input.push_back(-9927.00);
    } else if (expected_size == 2) {
        _input.push_back(-9927.00);
        _input.push_back(-9861.80);
    } else if (expected_size == 3) {
        _input.push_back(-9927.00);
        _input.push_back(-9861.80);
        _input.push_back(1.0); // bias
    } else {
        // Default: use 2 inputs (most common)
        _input.push_back(-9927.00);
        _input.push_back(-9861.80);
    }
    
    std::list<double> _label;
    _label.push_back(-9731.20);
    
    double delta = 0.00001;
    
    std::cout << "Using input size: " << _input.size() << std::endl;
    
    bool result = trainer.train_quantum(mdl._nn, 15000, _input, _label, delta);
    
    if (result) {
        std::cout << "QUANTUM TRAINING: SUCCESS!" << std::endl;
    } else {
        std::cout << "QUANTUM TRAINING: Completed" << std::endl;
    }
    
    return 0;
}