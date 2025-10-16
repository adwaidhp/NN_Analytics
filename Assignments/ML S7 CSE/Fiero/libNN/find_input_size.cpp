#include <iostream>
#include <list>
#include "model.h"

int main() {
    model mdl;
    
    std::cout << "=== CHECKING MODEL INPUT SIZE ===" << std::endl;
    
    // Check what size the model was initialized with
    std::cout << "Model input list size: " << mdl._nn.in.size() << std::endl;
    
    // Test with the correct size
    std::list<double> test_input;
    for (int i = 0; i < mdl._nn.in.size(); i++) {
        test_input.push_back(-9900.0 + i * 10.0); // Sample values
    }
    
    std::list<double> test_label;
    test_label.push_back(-9731.20);
    
    std::cout << "Created test input with size: " << test_input.size() << std::endl;
    
    // Try to set the input
    try {
        mdl._nn.set_input(test_input);
        std::cout << "SUCCESS: Input set correctly!" << std::endl;
        std::cout << "Your model expects " << test_input.size() << " input values" << std::endl;
    } catch (...) {
        std::cout << "FAILED: Input size mismatch" << std::endl;
    }
    
    return 0;
}