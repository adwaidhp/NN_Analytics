#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

struct Dataset {
    vector<double> input;
    vector<double> label;

    void generate(int n, double step = 1.0) {
        input.resize(n);
        label.resize(n);
        for (int i = 0; i < n; i++) {
            double x = i * step;
            input[i] = x;
            label[i] = sqrt(x); // true function
        }
    }
};

class Model {
public:
    vector<double> weights;

    Model(int size = 3) {
        weights.resize(size);
        for (auto &w : weights)
            w = 0.5 + static_cast<double>(rand()) / RAND_MAX; // random init 0.5-1.5
    }

    vector<double> predict(const vector<double> &input) {
        vector<double> output(input.size());
        for (size_t i = 0; i < input.size(); i++) {
            output[i] = weights[i % weights.size()] * sqrt(input[i]);
        }
        return output;
    }

    vector<double> compute_error(const vector<double> &output, const vector<double> &label) {
        vector<double> error(output.size());
        for (size_t i = 0; i < output.size(); i++)
            error[i] = label[i] - output[i];
        return error;
    }

    void update_weights(const vector<double> &input, const vector<double> &error, double lr = 0.01) {
        for (size_t i = 0; i < weights.size(); i++) {
            // simple gradient step
            double grad = 0.0;
            for (size_t j = i; j < input.size(); j += weights.size()) {
                grad += error[j] * sqrt(input[j]);
            }
            weights[i] += lr * grad;
        }
    }
};

#endif
