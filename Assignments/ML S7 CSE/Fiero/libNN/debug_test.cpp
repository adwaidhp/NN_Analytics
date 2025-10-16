#include <iostream>
#include <list>
#include "model.h"
#include "debug_quantum.h"  // Include the debug version

int main() {
    model mdl;
    debug_quantum trainer;
    
    std::list<double> _input;
    _input.push_back(-9927.00);
    _input.push_back(-9861.80);
    std::cout << "Created input with " << _input.size() << " elements" << std::endl;
    
    std::list<double> _label;
    _label.push_back(-9731.20);
    std::cout << "Created label with " << _label.size() << " elements" << std::endl;
    
    double delta = 0.00001;
    
    std::cout << "=== STARTING DEBUG RUN ===" << std::endl;
    bool result = trainer.train_quantum(mdl._nn, 10, _input, _label, delta);
    
    std::cout << "=== FINAL CHECK ===" << std::endl;
    std::cout << "Final input size: " << _input.size() << std::endl;
    std::cout << "Final label size: " << _label.size() << std::endl;
    std::cout << "Result: " << (result ? "SUCCESS" : "IN PROGRESS") << std::endl;
    
    return 0;
}