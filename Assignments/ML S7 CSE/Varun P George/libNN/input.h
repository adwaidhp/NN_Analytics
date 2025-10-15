#ifndef __INPUT_H__
#define __INPUT_H__

#include <list>
#include <assert.h>

class input
{
public:
    std::list<double> in;

    input() {}

    void set_input(std::list<double>& input_list)
    {
        assert(in.size() == input_list.size());
        auto it_in = in.begin();
        auto it_input = input_list.begin();

        while (it_in != in.end())
        {
            *it_in = *it_input;
            ++it_in;
            ++it_input;
        }
    }
};

#endif
