#include <iostream>
#include <list>
#include "network.h"
#include "error.h"
#include "activation.h"

int main()
{
    network nn;

    // 2 layers, 2 neurons each
    std::list<std::list<std::pair<ACT_FUN,double>>> node_list = {
        { {ACT_FUN::LINEAR, 0.0}, {ACT_FUN::LINEAR, 0.0} },
        { {ACT_FUN::LINEAR, 0.0}, {ACT_FUN::LINEAR, 0.0} }
    };

    nn.initialize(node_list);
    nn.set_learning_rate(0.1);

    // Example input
    std::list<double> input_values = {2.0, -1.0};
    auto it_input = input_values.begin();
    for(auto &n : nn.nodes.front()) {
        n.out = *it_input;   // Set input as output of input layer
        ++it_input;
    }

    // Example label for output layer
    std::list<double> label_values = {3.0, 0.0};
    auto it_label = label_values.begin();
    for(auto &n : nn.nodes.back()) {
        n.label.push_back(&(*it_label));
        ++it_label;
    }

    // Initialize errors for output layer
    for(auto &n : nn.nodes.back()) {
        double err_val = *(n.label.front()) - n.out; // simple error
        n.error.push_back(&err_val);
    }

    // Print inputs
    std::cout << "Inputs:\n";
    for(auto &n : nn.nodes.front()) {
        std::cout << n.out << " ";
    }
    std::cout << std::endl;

    // Predict
    nn.predict();

    // Print outputs
    std::cout << "Outputs:\n";
    for(auto &n : nn.nodes.back()) {
        std::cout << n.out << " ";
    }
    std::cout << std::endl;

    // Print errors
    std::cout << "Errors:\n";
    for(auto &n : nn.nodes.back()) {
        for(auto e : n.error) {
            std::cout << *e << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
