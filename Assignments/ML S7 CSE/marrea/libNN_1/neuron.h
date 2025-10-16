#ifndef _NEURON_H_
#define _NEURON_H_

#include <list>
#include "activation.h"
#include "derivative.h"

class neuron : public activation, public derivative {
public:
    double bias;
    double out;
    double delta;
    double learning_rate;
    std::list<double*> inputs;
    std::list<double> weights;

    ACT_FUN f;

    neuron(ACT_FUN func = relu, double lr = 0.01) : f(func), learning_rate(lr), bias(0), out(0), delta(0) {}

    void forward() {
        double sum = 0;
        auto it_in = inputs.begin();
        auto it_w = weights.begin();
        while(it_in != inputs.end() && it_w != weights.end()) {
            sum += **it_in * (*it_w);
            ++it_in; ++it_w;
        }
        out = function(f, sum + bias);
    }

    void backward(double error_signal) {
        double grad = error_signal * loss(f, out);
        auto it_w = weights.begin();
        for(auto &in_ptr : inputs) {
            *it_w += learning_rate * grad * **in_ptr;
            ++it_w;
        }
        bias += learning_rate * grad;
        delta = grad;
    }
};

#endif