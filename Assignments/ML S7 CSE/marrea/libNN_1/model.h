#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

struct Dataset {
    vector<double> input;
    vector<double> label;
};

class Model {
public:
    vector<double> weights;

    Model(int size = 3) {
        // Initialize weights with small random values for better convergence
        weights.resize(size);
        for (auto &w : weights)
            w = 0.1 * ((rand() % 10) / 10.0); 
    }

    // --- Predict: compute weighted sum of inputs ---
    vector<double> predict(const vector<double> &input) {
        double sum = 0.0;
        for (size_t i = 0; i < input.size(); i++)
            sum += input[i] * weights[i];
        return {sum}; // single scalar output
    }

    // --- Compute error (difference between expected and predicted sum) ---
    vector<double> compute_error(const vector<double> &output, const vector<double> &label) {
        vector<double> error(1);
        error[0] = label[0] - output[0];
        return error;
    }

    // --- Update weights using single scalar error ---
    void update_weights(const vector<double> &input, const vector<double> &error, double lr) {
        for (size_t i = 0; i < weights.size(); i++)
            weights[i] += lr * error[0] * input[i];
    }
};

#endif
