#ifndef __DATA_SET_H__
#define __DATA_SET_H__

#include <list>
#include <iostream>

class data_set
{
public:
    data_set()
    {
    }

    // Fixed dataset for XOR pattern
    std::list<std::list<double>> get_inputs()
    {
        std::list<std::list<double>> inputs = {
            {0.0, 0.0},
            {0.0, 1.0},
            {1.0, 0.0},
            {1.0, 1.0}
        };
        return inputs;
    }

    // Fixed outputs for XOR pattern
    std::list<std::list<double>> get_outputs()
    {
        std::list<std::list<double>> outputs = {
            {0.0},
            {1.0},
            {1.0},
            {0.0}
        };
        return outputs;
    }
};

#endif
