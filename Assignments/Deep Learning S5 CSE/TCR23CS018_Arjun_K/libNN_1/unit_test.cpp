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

    // Create a list of datasets for f(a,b,c) = (a+1, 2b+2, 3c+3)
    std::list<Dataset> datasets = {
        {{1, 2, 3}, {2, 6, 12}},   // {(1+1), (2*2+2), (3*3+3)}
        {{4, 1, 2}, {5, 4, 9}},    // {(4+1), (2*1+2), (3*2+3)}
        {{2, 3, 1}, {3, 8, 6}},    // {(2+1), (2*3+2), (3*1+3)}
        {{5, 4, 2}, {6, 10, 9}},   // {(5+1), (2*4+2), (3*2+3)}
        {{3, 5, 1}, {4, 12, 6}},   // {(3+1), (2*5+2), (3*1+3)}
        {{10, 2, 5}, {11, 6, 18}}  // {(10+1), (2*2+2), (3*5+3)}
    };

    double delta = 0.1; // Threshold for the error
    training obj = training();

    // Iterate over each dataset and train the model
    for(int i=0;i<1000;i++){    //epochs
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