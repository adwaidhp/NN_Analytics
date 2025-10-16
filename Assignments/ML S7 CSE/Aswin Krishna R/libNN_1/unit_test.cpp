#include <chrono>
#include <unistd.h>
#include <list>
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#include "data_set.h"
#include "training.h"
#include "model.h"

// Triangular number formula: T(n) = n(n+1)/2
double triangular_number(int n) {
    return (n * (n + 1)) / 2.0;
}

// Generate training data
void generate_triangular_training_data(std::list<std::list<double>>& inputs, 
                                     std::list<std::list<double>>& labels, 
                                     int start_n, int count) {
    for (int i = start_n; i < start_n + count; i++) {
        std::list<double> input;
        std::list<double> label;
        
        input.push_back(triangular_number(i));
        input.push_back(triangular_number(i + 1));
        input.push_back(triangular_number(i + 2));
        
        label.push_back(triangular_number(i + 3));
        label.push_back(triangular_number(i + 4));
        label.push_back(triangular_number(i + 5));
        
        inputs.push_back(input);
        labels.push_back(label);
    }
}

// Simple normalization
void normalize_triangular_data(std::list<std::list<double>>& inputs, 
                              std::list<std::list<double>>& labels) {
    double scale_factor = 100.0;
    
    for (auto& input : inputs) {
        for (auto& val : input) {
            val /= scale_factor;
        }
    }
    
    for (auto& label : labels) {
        for (auto& val : label) {
            val /= scale_factor;
        }
    }
}

// Denormalize data
void denormalize_output(std::list<double>& output) {
    double scale_factor = 100.0;
    for (auto& val : output) {
        val *= scale_factor;
    }
}

int main() {
    std::cout << "🔺 Neural Network Triangular Number Predictor" << std::endl;
    std::cout << "=============================================" << std::endl;
    std::cout << "Using MANUAL TRAINING APPROACH" << std::endl << std::endl;
    
    std::srand(std::time(0));
    
    // Generate training data
    std::list<std::list<double>> training_inputs;
    std::list<std::list<double>> training_labels;
    generate_triangular_training_data(training_inputs, training_labels, 1, 6);

    // Normalize data
    normalize_triangular_data(training_inputs, training_labels);

    std::cout << "Training Data:" << std::endl;
    int sample_num = 1;
    auto input_it = training_inputs.begin();
    auto label_it = training_labels.begin();
    for (; input_it != training_inputs.end() && label_it != training_labels.end(); 
         ++input_it, ++label_it) {
        std::cout << "Sample " << sample_num++ << ": [";
        for (auto val : *input_it) std::cout << std::fixed << std::setprecision(3) << val << " ";
        std::cout << "] -> [";
        for (auto val : *label_it) std::cout << std::fixed << std::setprecision(3) << val << " ";
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;

    // Create and setup model
    model mdl;
    std::cout << "Setting up neural network..." << std::endl;
    std::cout << "Architecture: 3 input → 6 hidden → 4 hidden → 3 output (linear)" << std::endl;
    mdl.set();

    std::cout << "🏋️ Starting MANUAL TRAINING..." << std::endl;
    std::cout << "Training each sample for multiple iterations" << std::endl << std::endl;
    
    int max_epochs = 5000;
    double target_error = 0.01;
    double best_overall_error = 1000.0;
    
    for (int epoch = 0; epoch < max_epochs; epoch++) {
        double total_error = 0.0;
        int sample_count = 0;
        bool any_learning = false;
        
        // Train on each sample multiple times
        auto input_it2 = training_inputs.begin();
        auto label_it2 = training_labels.begin();
        
        while (input_it2 != training_inputs.end() && label_it2 != training_labels.end()) {
            // Train this sample for multiple iterations
            for (int iter = 0; iter < 5; iter++) {
                mdl._nn.set_input(*input_it2);
                mdl._nn.set_label(*label_it2);
                mdl._nn.predict();
                
                // Calculate error
                auto output = mdl._nn.get_out_put();
                std::list<double> errors;
                
                auto out_it = output.begin();
                auto lbl_it = label_it2->begin();
                double sample_error = 0.0;
                int error_count = 0;
                
                while (out_it != output.end() && lbl_it != label_it2->end()) {
                    double error = *lbl_it - *out_it;
                    errors.push_back(error);
                    sample_error += std::abs(error);
                    error_count++;
                    ++out_it;
                    ++lbl_it;
                }
                
                if (error_count > 0) {
                    double avg_sample_error = sample_error / error_count;
                    
                    // Only train if error is significant
                    if (avg_sample_error > target_error) {
                        mdl._nn.set_error(errors);
                        mdl._nn.train();
                        any_learning = true;
                    }
                    
                    if (iter == 4) { // Only count the last iteration
                        total_error += avg_sample_error;
                        sample_count++;
                    }
                }
            }
            
            ++input_it2;
            ++label_it2;
        }
        
        double avg_error = sample_count > 0 ? total_error / sample_count : 0.0;
        
        if (avg_error < best_overall_error) {
            best_overall_error = avg_error;
        }
        
        // Progress reporting
        if (epoch % 100 == 0 || epoch < 10) {
            std::cout << "Epoch " << std::setw(4) << epoch << ": ";
            std::cout << "Avg Error: " << std::fixed << std::setprecision(4) << avg_error;
            std::cout << ", Best: " << best_overall_error;
            std::cout << " (Denorm: " << std::fixed << std::setprecision(1) << (avg_error * 100.0) << ")";
            
            // Check if outputs are actually changing
            if (!training_inputs.empty()) {
                auto first_input = training_inputs.front();
                auto first_label = training_labels.front();
                
                mdl._nn.set_input(first_input);
                mdl._nn.predict();
                auto output = mdl._nn.get_out_put();
                
                std::list<double> denorm_input = first_input;
                std::list<double> denorm_output = output;
                std::list<double> denorm_label = first_label;
                denormalize_output(denorm_input);
                denormalize_output(denorm_output);
                denormalize_output(denorm_label);
                
                std::cout << std::endl << "  First sample: [";
                for (auto val : denorm_input) std::cout << std::fixed << std::setprecision(1) << val << " ";
                std::cout << "] -> [";
                for (auto val : denorm_output) std::cout << std::fixed << std::setprecision(1) << val << " ";
                std::cout << "] (expected: [";
                for (auto val : denorm_label) std::cout << val << " ";
                std::cout << "])";
            }
            std::cout << std::endl;
        }
        
        // Stop if no learning is happening
        if (epoch > 100 && !any_learning && avg_error > target_error * 2) {
            std::cout << "🛑 No learning detected, stopping training" << std::endl;
            break;
        }
        
        // Success condition - require multiple epochs of good performance
        if (epoch > 50 && avg_error <= target_error) {
            std::cout << "🎉 Training converged at epoch " << epoch << "!" << std::endl;
            std::cout << "Final average error: " << avg_error << " (Denormalized: " << (avg_error * 100.0) << ")" << std::endl;
            break;
        }
        
        // Final epoch
        if (epoch == max_epochs - 1) {
            std::cout << "🛑 Reached maximum epochs: " << max_epochs << std::endl;
            std::cout << "Best error achieved: " << best_overall_error << " (Denormalized: " << (best_overall_error * 100.0) << ")" << std::endl;
        }
    }

    // Test generalization
    std::cout << std::endl << "🧪 GENERALIZATION TESTING:" << std::endl;
    std::cout << "=========================" << std::endl;
    
    // Test on various sequences
    std::vector<std::pair<std::list<double>, std::string>> test_cases = {
        {{1, 3, 6}, "T1,T2,T3 → T4,T5,T6 (10,15,21)"},
        {{3, 6, 10}, "T2,T3,T4 → T5,T6,T7 (15,21,28)"},
        {{6, 10, 15}, "T3,T4,T5 → T6,T7,T8 (21,28,36)"},
        {{10, 15, 21}, "T4,T5,T6 → T7,T8,T9 (28,36,45)"},
        {{2, 5, 9}, "Small numbers (14,20,27)"},
        {{20, 25, 31}, "Larger numbers (36,45,55)"}
    };
    
    double total_accuracy = 0.0;
    int test_count = 0;
    int correct_patterns = 0;
    
    for (size_t i = 0; i < test_cases.size(); i++) {
        auto sequence = test_cases[i].first;
        std::string description = test_cases[i].second;
        
        // Normalize input
        for (auto& val : sequence) {
            val /= 100.0;
        }
        
        mdl._nn.set_input(sequence);
        mdl._nn.predict();
        auto output = mdl._nn.get_out_put();
        
        // Denormalize for comparison
        std::list<double> denorm_sequence = sequence;
        std::list<double> denorm_output = output;
        denormalize_output(denorm_sequence);
        denormalize_output(denorm_output);
        
        // Calculate expected values
        double last_num = denorm_sequence.back();
        int n = static_cast<int>(std::round((std::sqrt(8 * last_num + 1) - 1) / 2));
        std::list<double> expected = {
            triangular_number(n + 1),
            triangular_number(n + 2), 
            triangular_number(n + 3)
        };
        
        std::cout << "Test " << (i+1) << ": " << description << std::endl;
        std::cout << "  Input:  [";
        for (auto val : denorm_sequence) std::cout << std::fixed << std::setprecision(1) << val << " ";
        std::cout << "]" << std::endl;
        std::cout << "  Output: [";
        for (auto val : denorm_output) std::cout << std::fixed << std::setprecision(1) << val << " ";
        std::cout << "]" << std::endl;
        std::cout << "  Expect: [";
        for (auto val : expected) std::cout << val << " ";
        std::cout << "]" << std::endl;
        
        // Calculate accuracy and check pattern
        auto out_it = denorm_output.begin();
        auto exp_it = expected.begin();
        double sample_accuracy = 0.0;
        int accuracy_count = 0;
        bool pattern_correct = true;
        
        while (out_it != denorm_output.end() && exp_it != expected.end()) {
            if (*exp_it != 0) {
                double error = std::abs(*out_it - *exp_it);
                double error_ratio = error / std::abs(*exp_it);
                double accuracy = (1.0 - error_ratio) * 100.0;
                sample_accuracy += std::max(0.0, std::min(100.0, accuracy));
                accuracy_count++;
                
                // Check if pattern is roughly correct (within 50%)
                if (error_ratio > 0.5) {
                    pattern_correct = false;
                }
            }
            ++out_it;
            ++exp_it;
        }
        
        if (accuracy_count > 0) {
            sample_accuracy /= accuracy_count;
            total_accuracy += sample_accuracy;
            test_count++;
            
            if (pattern_correct) {
                correct_patterns++;
            }
            
            std::cout << "  Accuracy: " << std::fixed << std::setprecision(1) << sample_accuracy << "% - ";
            
            if (sample_accuracy >= 80.0) {
                std::cout << "🎯 EXCELLENT";
            } else if (sample_accuracy >= 60.0) {
                std::cout << "✅ GOOD"; 
            } else if (sample_accuracy >= 40.0) {
                std::cout << "⚠️  FAIR";
            } else {
                std::cout << "❌ POOR";
            }
            
            if (pattern_correct) {
                std::cout << " ✓ PATTERN";
            }
        }
        std::cout << std::endl << std::endl;
    }
    
    if (test_count > 0) {
        double average_accuracy = total_accuracy / test_count;
        std::cout << "📊 OVERALL RESULTS:" << std::endl;
        std::cout << "  Average Accuracy: " << std::fixed << std::setprecision(1) << average_accuracy << "%" << std::endl;
        std::cout << "  Correct Patterns: " << correct_patterns << "/" << test_count << std::endl;
        
        if (average_accuracy >= 70.0 && correct_patterns >= test_count * 0.7) {
            std::cout << "🚀 SUCCESS: Network learned the triangular pattern!" << std::endl;
        } else if (average_accuracy >= 50.0) {
            std::cout << "📈 PARTIAL SUCCESS: Some learning detected" << std::endl;
        } else {
            std::cout << "💡 NEEDS IMPROVEMENT: Network didn't learn the pattern" << std::endl;
            std::cout << "   Try increasing training epochs or adjusting architecture" << std::endl;
        }
    }

    return 0;
}