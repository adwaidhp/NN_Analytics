#ifndef _MODEL_H_
#define _MODEL_H_

#include "network.h"
#include <list>

class model
{
public:
    network _nn = network();

    model() { }

    void set()
    {
        // --- topology ---
        // Layer 0: Input (3)
        // Layer 1: Hidden (6) - leaky_relu
        // Layer 2: Output (3) - linear
        std::list<std::list<std::pair<ACT_FUN, double>>> node_list;

        node_list.push_back({
            {ACT_FUN::linear, 0.0},
            {ACT_FUN::linear, 0.0},
            {ACT_FUN::linear, 0.0}
        });

        node_list.push_back({
            {ACT_FUN::leaky_relu, 0.0},
            {ACT_FUN::leaky_relu, 0.0},
            {ACT_FUN::leaky_relu, 0.0},
            {ACT_FUN::leaky_relu, 0.0},
            {ACT_FUN::leaky_relu, 0.0},
            {ACT_FUN::leaky_relu, 0.0}
        });

        node_list.push_back({
            {ACT_FUN::linear, 0.0},
            {ACT_FUN::linear, 0.0},
            {ACT_FUN::linear, 0.0}
        });

        _nn.initialize(node_list);

        double base_init = 0.01;

        // conservative learning rate for regression
        _nn.set_learning_rate(0.0005);

        // --- connect external inputs to layer 0 nodes ---
        // ip_to_nn assumed {to_layer, to_node, to_index, weight, trainable}
        ip_to_nn i0 = { 0u, 0u, 0u, 1.0, false };
        ip_to_nn i1 = { 0u, 1u, 0u, 1.0, false };
        ip_to_nn i2 = { 0u, 2u, 0u, 1.0, false };

        _nn.add(i0);
        _nn.add(i1);
        _nn.add(i2);

        for (unsigned int from = 0u; from < 3u; ++from)
{
    for (unsigned int to = 0u; to < 6u; ++to)
    {
        double init_w = base_init + 0.002 * ((from + to) % 3);
        nn_to_nn e = { 0u, from, 0u, 1u, to, 0u, init_w, true };
        _nn.add(e);
    }
}

// later, for hidden->output:
for (unsigned int from = 0u; from < 6u; ++from)
{
    for (unsigned int to = 0u; to < 3u; ++to)
    {
        double init_w = base_init; // small
        nn_to_nn e = { 1u, from, 0u, 2u, to, 0u, init_w, true };
        _nn.add(e);
    }
}
        // --- map output layer to global outputs ---
        nn_to_op o0 = { 2u, 0u, 0u, 1.0, false };
        nn_to_op o1 = { 2u, 1u, 0u, 1.0, false };
        nn_to_op o2 = { 2u, 2u, 0u, 1.0, false };

        _nn.add(o0);
        _nn.add(o1);
        _nn.add(o2);
    }
};

#endif
