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
        // Layer 1: 2 neurons (Hidden Layer)
        // Layer 2: 3 neurons (Output Layer)
        node_list = {
            {{ACT_FUN::tanh, 4.0}, {ACT_FUN::tanh, 4.0}, {ACT_FUN::tanh, 4.0}},

            {{ACT_FUN::relu, 0.3}, {ACT_FUN::relu, 5.0}},

            {{ACT_FUN::sigmoid, 3.0}, {ACT_FUN::sigmoid, 3.0}, {ACT_FUN::sigmoid, 3.0}}};

        _nn.initialize(node_list);

        // A higher learning rate for a linear problem
        _nn.set_learning_rate(0.0001); // changed learning rate to higher value

        // Connects 3 inputs to the 3 neurons of the first layer (Layer 0)
        ip_to_nn i1 = {0, 0, 0, 1.0, false};
        ip_to_nn i2 = {0, 1, 0, -1.0, false};
        ip_to_nn i3 = {0, 2, 0, -1.0, false};

        _nn.add(i1);
        _nn.add(i2);
        _nn.add(i3);

        // Connects all neurons in Layer 0 to all neurons in Layer 1 (Fully Connected)
       nn_to_nn n0n10 = {0, 0, 0, 1, 0, 0, 1.0, true};
	nn_to_nn n0n11 = {0, 0, 0, 1, 1, 0, 1.0, true};


	nn_to_nn n0n20 = {0, 1, 0, 1, 0, 0, 1.0, true};
	nn_to_nn n0n21 = {0, 1, 0, 1, 1, 0, 1.0, true};

	nn_to_nn n0n30 = {0, 2, 0, 1, 0, 0, 1.0, true};
	nn_to_nn n0n31 = {0, 2, 0, 1, 1, 0, 1.0, true};

        _nn.add(n0n10);
        _nn.add(n0n11);
        
        _nn.add(n0n20);
        _nn.add(n0n21);
        
        _nn.add(n0n30);
        _nn.add(n0n31);
        

        // Connects all neurons in Layer 1 to all neurons in Layer 2 (Fully Connected)
        nn_to_nn n1n20 = {1, 0, 0, 2, 0, 0, 1.0, true};
        nn_to_nn n1n21 = {1, 0, 0, 2, 1, 0, 1.0, true};
        nn_to_nn n1n22 = {1, 0, 0, 2, 2, 0, 1.0, true};

        nn_to_nn n1n23 = {1, 1, 0, 2, 0, 0, 1.0, true};
        nn_to_nn n1n24 = {1, 1, 0, 2, 1, 0, 1.0, true};
        nn_to_nn n1n25 = {1, 1, 0, 2, 2, 0, 1.0, true};


        _nn.add(n1n20);
        _nn.add(n1n21);
        _nn.add(n1n22);
        _nn.add(n1n23);
        _nn.add(n1n24);
        _nn.add(n1n25);
       

        // Connects the 3 neurons of the output layer (Layer 2) to the overall output
        nn_to_op o1 = {2, 0, 0, 1.0, false};
        nn_to_op o2 = {2, 1, 0, 1.0, false};
        nn_to_op o3 = {2, 2, 0, 1.0, false};

        _nn.add(o1);
        _nn.add(o2);
        _nn.add(o3);
    }
};

#endif
