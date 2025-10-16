#include <iostream>
#include <list>
#include <cmath>
#include <chrono>  // 🌟 ADD THIS LINE
#include "model.h"
#include "quantum_final.h"
#include "training.h"

void test_quantum_approach() {
    std::cout << "\n=== QUANTUM RESONANCE APPROACH ===" << std::endl;
    model mdl;
    mdl.set();
    
    quantum_final trainer;
    
    std::list<double> _input;
    _input.push_back(-9927.00);
    _input.push_back(-9861.80);
    _input.push_back(-9900.00);
    _input.push_back(-9850.00);
    
    std::list<double> _label;
    _label.push_back(-9731.20);
    
    // 🌟 FIXED: Added std::chrono namespace
    auto start = std::chrono::high_resolution_clock::now();
    bool result = trainer.train_quantum(mdl._nn, 15000, _input, _label, 0.00001);
    auto end = std::chrono::high_resolution_clock::now();
    
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    std::cout << "QUANTUM RESULTS:" << std::endl;
    std::cout << "Success: " << (result ? "YES" : "NO") << std::endl;
    std::cout << "Time: " << duration.count() << " ms" << std::endl;
    std::cout << "Innovation: Quantum Resonance Algorithm" << std::endl;
    std::cout << "Features: Quantum tunneling simulation, Resonance events" << std::endl;
}

void test_traditional_approach() {
    std::cout << "\n=== TRADITIONAL APPROACH ===" << std::endl;
    model mdl;
    mdl.set();
    
    training traditional_trainer;
    
    std::list<double> _input;
    _input.push_back(-9927.00);
    _input.push_back(-9861.80);
    _input.push_back(-9900.00);
    _input.push_back(-9850.00);
    
    std::list<double> _label;
    _label.push_back(-9731.20);
    
    // 🌟 FIXED: Added std::chrono namespace
    auto start = std::chrono::high_resolution_clock::now();
    bool result = traditional_trainer.train(mdl._nn, _input, _label, 0.00001);
    auto end = std::chrono::high_resolution_clock::now();
    
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    std::cout << "TRADITIONAL RESULTS:" << std::endl;
    std::cout << "Success: " << (result ? "YES" : "NO") << std::endl;
    std::cout << "Time: " << duration.count() << " ms" << std::endl;
    std::cout << "Method: Standard Gradient Descent" << std::endl;
}

int main() {
    std::cout << "=== COMPARING QUANTUM vs TRADITIONAL ===" << std::endl;
    
    test_quantum_approach();
    test_traditional_approach();
    
    return 0;
}