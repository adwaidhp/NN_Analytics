#ifndef NETWORK_H
#define NETWORK_H

#include "act_fun.h"
#include <list>
#include <utility>
#include <iostream>

struct neuron {
    ACT_FUN activation;
    double weight;
    neuron(ACT_FUN act, double w) : activation(act), weight(w) {}
};

class network {
public:
    std::list<neuron> in;  // Input neurons (simple example)
    
    void initialize(std::list<std::list<std::pair<ACT_FUN, double>>>& nodes) {
        // Example: just print structure
        std::cout << "Network initialized with " << nodes.size() << " layers.\n";
    }

    void add_neuron(const neuron& n) {
        in.push_back(n);
    }

    void add(const neuron& n) {
        in.push_back(n);
    }

    void predict() {
        std::cout << "Predicting...\n";
    }

    std::list<double> get_out_put() {
        std::list<double> out;
        for (auto& n : in) out.push_back(n.weight);  // dummy output
        return out;
    }
};

#endif // NETWORK_H