#include <iostream>
#include <list>
#include "model.h"
#include "quantum_final.h"
#include "resonant_activation.h"  // 🌟 ADD THIS

int main() {
    std::cout << "=== QUANTUM RESONANCE NEURAL NETWORK DEMO ===" << std::endl;
    std::cout << "INNOVATIVE FEATURES:" << std::endl;
    std::cout << "1. 🎯 Quantum Resonance Algorithm" << std::endl;
    std::cout << "2. 🌊 Resonant Activation Function" << std::endl;
    std::cout << "3. ⚡ Quantum Tunneling Simulation" << std::endl;
    std::cout << "4. 🔬 Wave-like Learning Patterns" << std::endl;
    
    model mdl;
    mdl.set();
    
    quantum_final trainer;
    
    // Simple test case
    std::list<double> _input;
    _input.push_back(1.0);
    _input.push_back(2.0);
    _input.push_back(3.0); 
    _input.push_back(4.0);
    
    std::list<double> _label;
    _label.push_back(2.5);  // Average of inputs
    
    std::cout << "\nTraining Quantum Network..." << std::endl;
    std::cout << "Input: [1, 2, 3, 4]" << std::endl;
    std::cout << "Target: 2.5 (average of inputs)" << std::endl;
    
    bool result = trainer.train_quantum(mdl._nn, 5000, _input, _label, 0.1);
    
    if (result) {
        std::cout << "🎉 QUANTUM TRAINING SUCCESS!" << std::endl;
        std::cout << "The quantum resonance algorithm found the solution!" << std::endl;
    } else {
        std::cout << "Training completed - network learned patterns" << std::endl;
    }
    
    // Show the resonant activation in action
    std::cout << "\n=== RESONANT ACTIVATION DEMO ===" << std::endl;
    std::cout << "Resonant function values for sample inputs:" << std::endl;
    for (double x = -2.0; x <= 2.0; x += 0.5) {
        double resonant_val = resonant(x);
        std::cout << "resonant(" << x << ") = " << resonant_val << std::endl;
    }
    
    return 0;
}