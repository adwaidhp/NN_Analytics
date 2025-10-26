#include <chrono>
#include <unistd.h>
#include <list>
#include <iostream>

#include "data_set.h"
#include "training.h"
#include "model.h"

// Define a structure to hold input and label lists
struct Dataset
{
    std::list<double> input;
    std::list<double> label;
};

int main()
{
    data_set dts = data_set();
    model mdl = model();
    mdl.set();

    std::list<Dataset> datasets = {
        // Linear datasets
        {{2, 4, 6}, {3, 5, 7}},     // y = x + 1
        {{1, 2, 3}, {2, 4, 6}},     // y = 2x

        // Quadratic datasets
        {{1, 3, 5}, {2, 10, 26}},   // y = x^2 + 1
        {{3, 5, 7}, {10, 26, 50}}   // y = x^2 + 1

    };

    double delta = 0.1; // Threshold for the error
    training obj = training();

    // Iterate over each dataset and train the model
    for(int i=0;i<60;i++){    //epochs
    for (auto &dataset : datasets)
    {
        bool result = obj.train(mdl._nn, dataset.input, dataset.label, delta);

        if (result)
        {
            std::cout << "Training successful" << std::endl;
        }
        else
        {
            std::cout << "Try again" << std::endl;
        }
    }
    std::cout << "in iteration: " << i << std::endl;
}

    return 0;
}
