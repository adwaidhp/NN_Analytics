#ifndef _MODEL_H_
#define _MODEL_H_

#include "network.h"
#include <cstdlib> // for rand()
#include <ctime>   // for time()
#include <list>
#include <utility>

class model {
public:
    network _nn = network();

    model() {
        srand(static_cast<unsigned>(time(0))); // seed for randomized weights
    }

    void set() {
        std::list<std::list<std::pair<ACT_FUN, double>>> node_list;

        // Architecture: Input Layer: 3, Hidden Layer: 3, Output Layer: 3
        node_list = {
            {{ACT_FUN::leaky_relu, 1.0}, {ACT_FUN::leaky_relu, 1.0}, {ACT_FUN::leaky_relu, 1.0}},
            {{ACT_FUN::leaky_relu, 1.0}, {ACT_FUN::leaky_relu, 1.0}, {ACT_FUN::leaky_relu, 1.0}},
            {{ACT_FUN::leaky_relu, 1.0}, {ACT_FUN::leaky_relu, 1.0}, {ACT_FUN::leaky_relu, 1.0}}
        };

        _nn.initialize(node_list);
        _nn.set_learning_rate(0.01);

        // Small random weight generator [-0.1, 0.1]
        auto w = []() { return ((double)rand() / RAND_MAX) * 0.2 - 0.1; };

        // -----------------------
        // Input → Layer 0
        // -----------------------
        ip_to_nn ip1{0, 0, 0, w(), false};
        ip_to_nn ip2{1, 0, 1, w(), false};
        ip_to_nn ip3{2, 0, 2, w(), false};

        _nn.add(ip1);
        _nn.add(ip2);
        _nn.add(ip3);

        // -----------------------
        // Layer 0 → Layer 1
        // -----------------------
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                nn_to_nn conn{0, (unsigned)i, 0, 1, (unsigned)j, 0, w(), true};
                _nn.add(conn);
            }
        }

        // -----------------------
        // Layer 1 → Layer 2
        // -----------------------
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                nn_to_nn conn{1, (unsigned)i, 0, 2, (unsigned)j, 0, w(), true};
                _nn.add(conn);
            }
        }

        // -----------------------
        // Layer 2 → Output
        // -----------------------
        nn_to_op op1{2, 0, 0, w(), false};
        nn_to_op op2{2, 1, 1, w(), false};
        nn_to_op op3{2, 2, 2, w(), false};

        _nn.add(op1);
        _nn.add(op2);
        _nn.add(op3);
    }
};

#endif
