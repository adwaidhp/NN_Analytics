#include <iostream>
#include <list>
#include <cmath>
#include "correct_model.h"
#include "quantum_final.h"

int main() {
    std::cout << "=== TESTING WITH YOUR DATA (Normalized) ===" << std::endl;
    
    correct_model mdl;
    mdl.set();
    
    quantum_final trainer;
    
    // 🌟 YOUR DATA BUT NORMALIZED (divided by 10000)
    std::list<double> _input;
    _input.push_back(-0.9927);   // -9927 / 10000
    _input.push_back(-0.98618);  // -9861.8 / 10000  
    _input.push_back(-0.9927);   // duplicate
    _input.push_back(-0.98618);  // duplicate
    
    std::list<double> _label;
    _label.push_back(-0.97312);  // -9731.2 / 10000
    
    std::cout << "Normalized Input: [";
    for (auto val : _input) std::cout << val << " ";
    std::cout << "]" << std::endl;
    std::cout << "Normalized Target: " << _label.front() << std::endl;
    
    bool result = trainer.train_quantum(mdl._nn, 5000, _input, _label, 0.01);
    
    // Test
    mdl._nn.set_input(_input);
    mdl._nn.predict();
    auto output = mdl._nn.get_out_put();
    
    std::cout << "\n📊 RESULTS:" << std::endl;
    std::cout << "Predicted: " << output.front() << std::endl;
    std::cout << "Expected: " << _label.front() << std::endl;
    
    double error = std::abs(output.front() - _label.front());
    std::cout << "Error: " << error << std::endl;
    
    if (error < 0.1) {
        std::cout << "✅ SUCCESS! Quantum Resonance is working!" << std::endl;
    } else {
        std::cout << "🔄 Learning in progress" << std::endl;
    }
    
    return 0;
}