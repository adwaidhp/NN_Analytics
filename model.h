#ifndef _MODEL_H_
#define _MODEL_H_

#include "network.h"
#include <cstdlib>
#include <ctime>

class model
{
public:
    network _nn = network();

    model() { std::srand(static_cast<unsigned>(std::time(nullptr))); }

    double rand_weight(double scale = 0.05)  // ⬅️ smaller weight range
    {
        return ((std::rand() % 2000) / 1000.0 - 1.0) * scale;
    }

    void set()
    {
        std::list<std::list<std::pair<ACT_FUN, double>>> node_list;

        // 3 input, 4 hidden, 1 output
        node_list = {
            {{ACT_FUN::tanh_act, 0.0}, {ACT_FUN::tanh_act, 0.0}, {ACT_FUN::tanh_act, 0.0}},
            {{ACT_FUN::tanh_act, 0.0}, {ACT_FUN::tanh_act, 0.0}, {ACT_FUN::tanh_act, 0.0}, {ACT_FUN::tanh_act, 0.0}},
            {{ACT_FUN::tanh_act, 0.0}}
        };

        _nn.initialize(node_list);
        _nn.set_learning_rate(0.0001); // ⬅️ smaller LR

        // Input to first layer
        ip_to_nn i1 = {0, 0, 0, rand_weight(), true};
        ip_to_nn i2 = {0, 1, 0, rand_weight(), true};
        ip_to_nn i3 = {0, 2, 0, rand_weight(), true};
        _nn.add(i1);
        _nn.add(i2);
        _nn.add(i3);

        // Layer 0 to Layer 1
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                nn_to_nn conn = {0, static_cast<unsigned>(i), 0, 1, static_cast<unsigned>(j), 0, rand_weight(), true};
                _nn.add(conn);
            }
        }

        // Layer 1 to Layer 2
        for (int i = 0; i < 4; ++i)
        {
            nn_to_nn conn = {1, static_cast<unsigned>(i), 0, 2, 0, 0, rand_weight(), true};
            _nn.add(conn);
        }

        // Output
        nn_to_op o1 = {2, 0, 0, rand_weight(), false};
        _nn.add(o1);
    }
};

#endif
