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
        weights.resize(size, 1.0); // initialize weights to 1.0
    }

    vector<double> predict(const vector<double> &input) {
        vector<double> output(input.size());
        for (size_t i = 0; i < input.size(); i++)
            output[i] = input[i] * weights[i]; // linear model
        return output;
    }

    vector<double> compute_error(const vector<double> &output, const vector<double> &label) {
        vector<double> error(output.size());
        for (size_t i = 0; i < output.size(); i++)
            error[i] = label[i] - output[i];
        return error;
    }

    void update_weights(const vector<double> &input, const vector<double> &error, double lr) {
    for (size_t i = 0; i < weights.size(); i++)
        weights[i] += lr * error[i] / (input[i] != 0 ? input[i] : 1); // normalize by input
}

};

#endif
