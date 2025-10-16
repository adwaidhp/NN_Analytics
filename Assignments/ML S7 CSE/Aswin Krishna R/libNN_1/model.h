#ifndef _MODEL_H_
#define _MODEL_H_

#include "network.h"
#include <cstdlib>
#include <cmath>

class model
{
public:
    network _nn;

    model() : _nn(network())
    {
    }

    void set()
    {
        std::list<std::list<std::pair<ACT_FUN, double>>> node_list;

        // Improved architecture with better capacity
        node_list = {
            {{ACT_FUN::linear, 0.0}, {ACT_FUN::linear, 0.0}, {ACT_FUN::linear, 0.0}},  // Input layer (3)
            {{ACT_FUN::tanh_func, 0.0}, {ACT_FUN::tanh_func, 0.0}, {ACT_FUN::tanh_func, 0.0}, 
             {ACT_FUN::tanh_func, 0.0}, {ACT_FUN::tanh_func, 0.0}, {ACT_FUN::tanh_func, 0.0}},  // Hidden layer 1 (6)
            {{ACT_FUN::tanh_func, 0.0}, {ACT_FUN::tanh_func, 0.0}, {ACT_FUN::tanh_func, 0.0}, 
             {ACT_FUN::tanh_func, 0.0}},  // Hidden layer 2 (4)
            {{ACT_FUN::linear, 0.0}, {ACT_FUN::linear, 0.0}, {ACT_FUN::linear, 0.0}}   // Output layer (3)
        };

        _nn.initialize(node_list);
        _nn.set_learning_rate(0.01);  // Reduced learning rate

        // Input connections - Xavier/Glorot initialization
        for (unsigned int i = 0; i < 3; i++) {
            ip_to_nn conn;
            conn.to_layer = 0;
            conn.to_node = i;
            // Better weight initialization
            double range = sqrt(6.0 / (3 + 6));  // Xavier initialization
            conn.weight = ((double)std::rand() / RAND_MAX) * 2 * range - range;
            conn.trainable = true;
            _nn.add(conn);
        }

        // Input to first hidden - full connectivity
        for (unsigned int i = 0; i < 3; i++) {
            for (unsigned int j = 0; j < 6; j++) {
                nn_to_nn conn;
                conn.from_layer = 0;
                conn.from_node = i;
                conn.to_layer = 1;
                conn.to_node = j;
                double range = sqrt(6.0 / (3 + 6));
                conn.weight = ((double)std::rand() / RAND_MAX) * 2 * range - range;
                conn.trainable = true;
                _nn.add(conn);
            }
        }

        // First hidden to second hidden
        for (unsigned int i = 0; i < 6; i++) {
            for (unsigned int j = 0; j < 4; j++) {
                nn_to_nn conn;
                conn.from_layer = 1;
                conn.from_node = i;
                conn.to_layer = 2;
                conn.to_node = j;
                double range = sqrt(6.0 / (6 + 4));
                conn.weight = ((double)std::rand() / RAND_MAX) * 2 * range - range;
                conn.trainable = true;
                _nn.add(conn);
            }
        }

        // Second hidden to output
        for (unsigned int i = 0; i < 4; i++) {
            for (unsigned int j = 0; j < 3; j++) {
                nn_to_nn conn;
                conn.from_layer = 2;
                conn.from_node = i;
                conn.to_layer = 3;
                conn.to_node = j;
                double range = sqrt(6.0 / (4 + 3));
                conn.weight = ((double)std::rand() / RAND_MAX) * 2 * range - range;
                conn.trainable = true;
                _nn.add(conn);
            }
        }

        // Output connections
        for (unsigned int i = 0; i < 3; i++) {
            nn_to_op output_conn;
            output_conn.from_layer = 3;
            output_conn.from_node = i;
            output_conn.weight = 1.0;
            output_conn.trainable = false;
            _nn.add(output_conn);
        }
    }
};

#endif