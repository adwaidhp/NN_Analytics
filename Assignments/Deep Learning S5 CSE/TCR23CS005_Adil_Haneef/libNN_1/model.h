#ifndef _MODEL_H_
#define _MODEL_H_

#include "network.h"

class model {
public:
    network _nn;

    model() {}

    void set() {
        // Define layers: 4 layers, 3 neurons each
        std::list<std::list<std::pair<ACT_FUN, double>>> node_list = {
            {{ACT_FUN::leaky_relu, 4.0}, {ACT_FUN::leaky_relu, 4.0}, {ACT_FUN::leaky_relu, 4.0}},
            {{ACT_FUN::leaky_relu, 5.0}, {ACT_FUN::leaky_relu, 2.0}, {ACT_FUN::leaky_relu, 4.0}},
            {{ACT_FUN::leaky_relu, 3.0}, {ACT_FUN::leaky_relu, 3.0}, {ACT_FUN::leaky_relu, 3.0}},
            {{ACT_FUN::leaky_relu, 3.0}, {ACT_FUN::leaky_relu, 3.0}, {ACT_FUN::leaky_relu, 3.0}}
        };

        _nn.initialize(node_list);
        _nn.set_learning_rate(0.00001);

        // Input → first layer connections
        ip_to_nn i1 = {0u, 0u, 0u, 1.0, false};
        ip_to_nn i2 = {0u, 1u, 0u, -1.0, false};
        ip_to_nn i3 = {0u, 2u, 0u, -1.0, false};

        _nn.add(i1);
        _nn.add(i2);
        _nn.add(i3);

        // Fully connect Layer 0 → Layer 1, Layer 1 → Layer 2
        for (unsigned int from_layer = 0u; from_layer < 3u; ++from_layer) {
            for (unsigned int from_neuron = 0u; from_neuron < 3u; ++from_neuron) {
                for (unsigned int to_neuron = 0u; to_neuron < 3u; ++to_neuron) {
                    nn_to_nn conn = {
                        from_layer,
                        from_neuron,
                        0u,
                        static_cast<unsigned int>(from_layer + 1u),
                        to_neuron,
                        0u,
                        1.0,
                        true
                    };
                    _nn.add(conn);
                }
            }
        }

        // Output layer connections
        for (unsigned int i = 0u; i < 3u; ++i) {
            nn_to_op o = {2u, i, 0u, 1.0, false};
            _nn.add(o);
        }
    }
};

#endif
