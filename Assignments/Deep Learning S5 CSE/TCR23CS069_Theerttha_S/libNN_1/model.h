#ifndef _MODEL_H_
#define _MODEL_H_

#include "network.h"

                                              class model
{
public:
    network _nn = network();

    model()
    {
    }

    void set()
    {
        std::list<std::list<std::pair<ACT_FUN, double>>> node_list;

        // This defines a 3-layer network:
        // Layer 0: 3 neurons (Input Layer)
        // Layer 1: 3 neurons (Hidden Layer)
        // Layer 2: 3 neurons (Output Layer)
        node_list = {
            {{ACT_FUN::leaky_relu, 4.0}, {ACT_FUN::leaky_relu, 4.0}, {ACT_FUN::leaky_relu, 4.0}},

            {{ACT_FUN::leaky_relu, 5.0}, {ACT_FUN::leaky_relu, 2.0}, {ACT_FUN::leaky_relu, 4.0}},
            {{ACT_FUN::leaky_relu, 5.0}, {ACT_FUN::leaky_relu, 2.0}, {ACT_FUN::leaky_relu, 4.0}},

            {{ACT_FUN::leaky_relu, 3.0}, {ACT_FUN::leaky_relu, 3.0}, {ACT_FUN::leaky_relu, 3.0}}};

        _nn.initialize(node_list);

        // A higher learning rate for a linear problem
        _nn.set_learning_rate(0.0001);

        // Connects 3 inputs to the 3 neurons of the first layer (Layer 0)
        ip_to_nn i1 = {0, 0, 0, 1.0, false};
        ip_to_nn i2 = {0, 1, 0, -1.0, false};
        ip_to_nn i3 = {0, 2, 0, -1.0, false};

        _nn.add(i1);
        _nn.add(i2);
        _nn.add(i3);

        // Connects all neurons in Layer 0 to all neurons in Layer 1 (Fully Connected)
        nn_to_nn n0n00 = {0, 0, 0, 1, 0, 0, 1.0, true};
        nn_to_nn n0n01 = {0, 0, 0, 1, 1, 0, 1.0, true};
        nn_to_nn n0n02 = {0, 0, 0, 1, 2, 0, 1.0, true};

        nn_to_nn n0n10 = {0, 1, 0, 1, 0, 0, 1.0, true};
        nn_to_nn n0n11 = {0, 1, 0, 1, 1, 0, 1.0, true};
        nn_to_nn n0n12 = {0, 1, 0, 1, 2, 0, 1.0, true};

        nn_to_nn n0n20 = {0, 2, 0, 1, 0, 0, 1.0, true};
        nn_to_nn n0n21 = {0, 2, 0, 1, 1, 0, 1.0, true};
        nn_to_nn n0n22 = {0, 2, 0, 1, 2, 0, 1.0, true};

        _nn.add(n0n00);
        _nn.add(n0n01);
        _nn.add(n0n02);
        _nn.add(n0n10);
        _nn.add(n0n11);
        _nn.add(n0n12);
        _nn.add(n0n20);
        _nn.add(n0n21);
        _nn.add(n0n22);
        

        // Connects all neurons in Layer 1 to all neurons in Layer 2 (Fully Connected)
        nn_to_nn n1n00 = {1, 0, 0, 2, 0, 0, 1.0, true};
        nn_to_nn n1n01 = {1, 0, 0, 2, 1, 0, 1.0, true};
        nn_to_nn n1n02 = {1, 0, 0, 2, 2, 0, 1.0, true};

        nn_to_nn n1n10 = {1, 1, 0, 2, 0, 0, 1.0, true};
        nn_to_nn n1n11= {1, 1, 0, 2, 1, 0, 1.0, true};
        nn_to_nn n1n12 = {1, 1, 0, 2, 2, 0, 1.0, true};

        nn_to_nn n1n20 = {1, 2, 0, 2, 0, 0, 1.0, true};
        nn_to_nn n1n21 = {1, 2, 0, 2, 1, 0, 1.0, true};
        nn_to_nn n1n22 = {1, 2, 0, 2, 2, 0, 1.0, true};

        _nn.add(n1n00);
        _nn.add(n1n01);
        _nn.add(n1n02);
        _nn.add(n1n10);
        _nn.add(n1n11);
        _nn.add(n1n12);
        _nn.add(n1n20);
        _nn.add(n1n21);
        _nn.add(n1n22);
        
        nn_to_nn n2n00 = {2, 0, 0, 3, 0, 0, 1.0, true};
        nn_to_nn n2n01 = {2, 0, 0, 3, 1, 0, 1.0, true};
        nn_to_nn n2n02 = {2, 0, 0, 3, 2, 0, 1.0, true};

        nn_to_nn n2n10 = {2, 1, 0, 3, 0, 0, 1.0, true};
        nn_to_nn n2n11= {2, 1, 0, 3, 1, 0, 1.0, true};
        nn_to_nn n2n12 = {2, 1, 0, 3, 2, 0, 1.0, true};

        nn_to_nn n2n20 = {2, 2, 0, 3, 0, 0, 1.0, true};
        nn_to_nn n2n21 = {2, 2, 0, 3, 1, 0, 1.0, true};
        nn_to_nn n2n22 = {2, 2, 0, 3, 2, 0, 1.0, true};
        // Connects the 3 neurons of the output layer (Layer 2) to the overall output
        nn_to_op o1 = {3, 0, 0, 1.0, false};
        nn_to_op o2 = {3, 1, 0, 1.0, false};
        nn_to_op o3 = {3, 2, 0, 1.0, false};

        _nn.add(o1);
        _nn.add(o2);
        _nn.add(o3);
    }
};

#endif