#include <iostream>
#include <list>
#include <cmath>
#include "model.h"
#include "quantum_final.h"

int main() {
    model mdl;
    
    std::cout << "=== TESTING RESONANT ACTIVATION ===" << std::endl;
    
    // 🌟 FIXED: Pass MODEL_TYPE argument to set()
    mdl.set(MODEL_TYPE::REGRESSION);
    
    std::cout << "Network has " << mdl._nn.in.size() << " inputs" << std::endl;
    
    quantum_final trainer;
    
    // 🌟 USE 4 INPUTS TO MATCH NETWORK
    std::list<double> _input;
    _input.push_back(-9927.00);   // Input 1
    _input.push_back(-9861.80);   // Input 2
    _input.push_back(-9927.00);   // Input 3 (same as input 1)
    _input.push_back(-9861.80);   // Input 4 (same as input 2)
    
    std::list<double> _label;
    _label.push_back(-9731.20);
    
    double delta = 0.00001;
    
    std::cout << "Training with " << _input.size() << " inputs" << std::endl;
    std::cout << "Starting Quantum Training with Resonant Activation..." << std::endl;
    
    // Train and track detailed progress
    bool result = trainer.train_quantum(mdl._nn, 15000, _input, _label, delta);
    
    // 🎯 DETAILED ANALYSIS
    std::cout << "\n=== DETAILED ANALYSIS ===" << std::endl;
    
    // Final predictions
    mdl._nn.set_input(_input);
    mdl._nn.predict();
    auto final_output = mdl._nn.get_out_put();
    auto final_error = trainer.difference(final_output, _label);
    
    std::cout << "FINAL RESULTS:" << std::endl;
    std::cout << "Input: [";
    for (auto val : _input) std::cout << val << " ";
    std::cout << "]" << std::endl;
    
    std::cout << "Label: [";
    for (auto val : _label) std::cout << val << " ";
    std::cout << "]" << std::endl;
    
    std::cout << "Output: [";
    for (auto val : final_output) std::cout << val << " ";
    std::cout << "]" << std::endl;
    
    std::cout << "Error: [";
    for (auto val : final_error) std::cout << val << " ";
    std::cout << "]" << std::endl;
    
    // Calculate RMS Error
    double rms_error = 0;
    int count = 0;
    auto out_it = final_output.begin();
    auto label_it = _label.begin();
    
    while (out_it != final_output.end() && label_it != _label.end()) {
        double diff = *out_it - *label_it;
        rms_error += diff * diff;
        count++;
        out_it++;
        label_it++;
    }
    
    if (count > 0) {
        rms_error = sqrt(rms_error / count);
        std::cout << "RMS Error: " << rms_error << std::endl;
    }
    
    if (result) {
        std::cout << "🎉 RESONANT ACTIVATION: SUCCESS!" << std::endl;
    } else {
        std::cout << "Resonant Activation: Training completed" << std::endl;
    }
    
    return 0;
}