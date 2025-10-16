#ifndef _MODEL_H_
#define _MODEL_H_

#include "network.h"

class model
{
public:
    network _nn = network();

    model() {}

    void set()
    {
        std::list<std::list<std::pair<ACT_FUN, double>>> node_list;

        // Layer 0: Input layer (3 neurons) — no activation
        // Layer 1: Hidden layer (3 neurons) — tanh for nonlinear learning
        // Layer 2: Output layer (3 neurons) — identity for continuous output
        node_list = {
            {{ACT_FUN::leaky_relu, 1.0}, {ACT_FUN::leaky_relu, 1.0}, {ACT_FUN::leaky_relu, 1.0}},
            {{ACT_FUN::sigmoid, 1.0}, {ACT_FUN::sigmoid, 1.0}, {ACT_FUN::sigmoid, 1.0}},
            {{ACT_FUN::leaky_relu , 1.0}, {ACT_FUN::leaky_relu, 1.0}, {ACT_FUN::leaky_relu, 1.0}}
        };

        _nn.initialize(node_list);

        // Slightly higher learning rate for faster convergence
        _nn.set_learning_rate(0.001);

        // Input to layer 0 connections
        ip_to_nn i1 = {0, 0, 0, 1.0, false};
        ip_to_nn i2 = {0, 1, 0, 1.0, false};
        ip_to_nn i3 = {0, 2, 0, 1.0, false};

        _nn.add(i1);
        _nn.add(i2);
        _nn.add(i3);

        // Fully connect Layer 0 → Layer 1
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                nn_to_nn conn = {0, i, 0, 1, j, 0, 1.0, true};
                _nn.add(conn);
            }
        }

        // Fully connect Layer 1 → Layer 2
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                nn_to_nn conn = {1, i, 0, 2, j, 0, 1.0, true};
                _nn.add(conn);
            }
        }

        // Output layer connections
        for (int i = 0; i < 3; i++) {
            nn_to_op out_conn = {2, i, 0, 1.0, false};
            _nn.add(out_conn);
        }
    }
};

#endif
