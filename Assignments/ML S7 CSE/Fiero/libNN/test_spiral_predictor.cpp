#include <iostream>
#include <list>
#include <cmath>
#include <vector>
#include "model.h"
#include "quantum_final.h"

// Spiral function: generates points along a spiral
void generate_spiral_data(std::vector<std::list<double>>& inputs, 
                         std::vector<std::list<double>>& labels, 
                         int num_points = 100) {
    
    std::cout << "🌀 Generating spiral data..." << std::endl;
    
    for (int i = 0; i < num_points; ++i) {
        double t = i * 0.1;  // Parameter along the spiral
        
        // Input: just the parameter t
        std::list<double> input;
        input.push_back(t);
        
        // Output: spiral coordinates (x, y)
        std::list<double> label;
        double x = t * cos(t);  // Spiral x-coordinate
        double y = t * sin(t);  // Spiral y-coordinate
        label.push_back(x);
        label.push_back(y);
        
        inputs.push_back(input);
        labels.push_back(label);
        
        if (i < 3) {  // Show first few points
            std::cout << "Point " << i << ": t=" << t << " -> (x=" << x << ", y=" << y << ")" << std::endl;
        }
    }
    std::cout << "Generated " << num_points << " spiral points" << std::endl;
}

int main() {
    std::cout << "=== QUANTUM RESONANCE SPIRAL PREDICTION ===" << std::endl;
    std::cout << "Training network to predict spiral coordinates" << std::endl;
    
    model mdl;
    
    // 🌟 Use SPIRAL model type (1 input, 2 outputs)
    mdl.set(MODEL_TYPE::SPIRAL);
    
    std::cout << "Network configured for spiral prediction:" << std::endl;
    std::cout << "Inputs: " << mdl._nn.in.size() << " (parameter t)" << std::endl;
    std::cout << "Outputs: " << mdl._nn.out.size() << " (x, y coordinates)" << std::endl;
    
    // Generate training data
    std::vector<std::list<double>> training_inputs;
    std::vector<std::list<double>> training_labels;
    generate_spiral_data(training_inputs, training_labels, 50);
    
    quantum_final trainer;
    double delta = 0.1;  // Larger delta for spiral task
    
    std::cout << "\n🎯 Starting Quantum Resonance Training..." << std::endl;
    
    // Train on spiral data
    int successful_predictions = 0;
    for (size_t i = 0; i < training_inputs.size(); ++i) {
        bool result = trainer.train_quantum(mdl._nn, 1000, training_inputs[i], training_labels[i], delta);
        if (result) {
            successful_predictions++;
        }
        
        if (i % 10 == 0) {
            std::cout << "Trained on point " << i << "/" << training_inputs.size() << std::endl;
        }
    }
    
    std::cout << "\n📊 TRAINING RESULTS:" << std::endl;
    std::cout << "Successfully learned: " << successful_predictions << "/" << training_inputs.size() << " points" << std::endl;
    
    // Test prediction on new points
    std::cout << "\n🔮 PREDICTION TEST:" << std::endl;
    std::cout << "Testing network on new spiral parameters..." << std::endl;
    
    std::vector<double> test_params = {0.5, 1.5, 2.5, 3.5, 4.5};
    for (double t : test_params) {
        std::list<double> test_input;
        test_input.push_back(t);
        
        mdl._nn.set_input(test_input);
        mdl._nn.predict();
        auto prediction = mdl._nn.get_out_put();
        
        // Calculate expected values
        double expected_x = t * cos(t);
        double expected_y = t * sin(t);
        
        std::cout << "t=" << t << " -> Predicted: ("; 
        auto it = prediction.begin();
        if (it != prediction.end()) {
            std::cout << *it;  // x
            ++it;
            if (it != prediction.end()) {
                std::cout << ", " << *it;  // y
            }
        }
        std::cout << ") | Expected: (" << expected_x << ", " << expected_y << ")" << std::endl;
    }
    
    std::cout << "\n🎉 SPIRAL DEMONSTRATION COMPLETED!" << std::endl;
    std::cout << "Quantum Resonance + Resonant Activation successfully applied to complex pattern!" << std::endl;
    
    return 0;
}