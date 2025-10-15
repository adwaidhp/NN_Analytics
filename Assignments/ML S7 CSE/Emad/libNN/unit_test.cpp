#include <iostream>
#include <list>
#include <cassert>
#include "input.h"
#include "label.h"
#include "error.h"

// Example: dummy training function
void train_example(input &inp, label &lbl) {
    error err;

    // Ensure sizes match
    if(inp.in.size() != lbl.lbl.size()) {
        std::cerr << "Input and label sizes do not match!" << std::endl;
        return;
    }

    // Simple dummy training: compute difference as error
    std::list<double> e;
    auto it_in = inp.in.begin();
    auto it_lbl = lbl.lbl.begin();
    while (it_in != inp.in.end() && it_lbl != lbl.lbl.end()) {
        e.push_back(*it_lbl - *it_in); // error = label - input
        ++it_in;
        ++it_lbl;
    }

    err.err = e;
    err.print();
}

int main() {
    // Example input and label (same size!)
    std::list<double> raw_input = {7000.6, -2299.6};
    std::list<double> raw_label = {8876.6, 4321.0}; // must have same number of elements as input

    // Normalize (optional, for stable training)
    double max_val = 10000.0;
    std::list<double> norm_input;
    std::list<double> norm_label;

    for(auto val : raw_input) norm_input.push_back(val / max_val);
    for(auto val : raw_label) norm_label.push_back(val / max_val);

    input inp(norm_input);
    label lbl(norm_label);

    inp.print();
    lbl.print();

    train_example(inp, lbl);

    std::cout << "Training step done!" << std::endl;
    return 0;
}
