#ifndef __NETWORK_H__
#define __NETWORK_H__

#include <list>
#include <iostream>
#include <cassert>
#include "neuron.h"

class network : public neuron
{
public:
    std::list<std::list<node>> nodes;

    network() {}

    void initialize(std::list<std::list<std::pair<ACT_FUN,double>>> node_list)
    {
        unsigned int l_index = 0;
        for (auto &layer : node_list)
        {
            std::list<node> temp_layer;
            unsigned int p_index = 0;
            for (auto &n : layer)
            {
                node temp_node;
                temp_node.f = n.first;
                temp_node.b = n.second;
                temp_node.l_index = l_index;
                temp_node.p_index = p_index;
                temp_layer.push_back(temp_node);
                p_index++;
            }
            nodes.push_back(temp_layer);
            l_index++;
        }
    }

    void set_learning_rate(double _rate) { learning_rate = _rate; }

    void predict()
    {
        for (auto &layer : nodes)
            for (auto n_id = layer.begin(); n_id != layer.end(); ++n_id)
            {
                in_forward = true;
                forward(n_id);
                in_forward = false;
            }
    }

    void train()
    {
        for (auto l_id = nodes.end(); l_id != nodes.begin();)
        {
            --l_id;
            for (auto n_id = l_id->begin(); n_id != l_id->end(); ++n_id)
            {
                in_backward = true;
                backward(n_id);
                in_backward = false;
            }
        }
    }
};

#endif
