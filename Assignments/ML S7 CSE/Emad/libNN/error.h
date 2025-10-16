#include <list>
#include <iostream>
#include <cassert>  // <-- make sure assert is included

class error
{
public:
    std::list<double> err;

    error() {}

    // Initialize error list with given size, filled with zeros
    error(size_t size) : err(size, 0.0) {}

    void set_error(std::list<double>& error)
    {
        assert(err.size() == error.size());

        auto it_err = err.begin();
        auto it_error = error.begin();

        while (it_err != err.end())
        {
            *it_err = *it_error;
            ++it_err;
            ++it_error;
        }
    }

    void print()
    {
        std::cout << "Error: [";
        for (auto field : err)
        {
            printf("%f ", field);
        }
        std::cout << "]" << std::endl;
    }
};
