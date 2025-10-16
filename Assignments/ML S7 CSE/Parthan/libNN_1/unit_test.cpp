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

    // Create a list of datasets
    std::list<Dataset> datasets = {
        {{4, 25, 16}, {2, 5, 4}},
        {{9, 36, 49}, {3, 6, 7}},
        {{0.81, 0.25, 0.36}, {0.9, 0.5, 0.6}},
        {{1, 4, 9}, {1, 2, 3}},
        {{16, 64, 100}, {4, 8, 10}},
        {{2.25, 6.25, 12.25}, {1.5, 2.5, 3.5}},
        {{0.04, 0.16, 0.36}, {0.2, 0.4, 0.6}},
        {{49, 121, 169}, {7, 11, 13}},
        {{0.09, 0.49, 1.21}, {0.3, 0.7, 1.1}},
        {{25, 81, 121}, {5, 9, 11}}
        // Add more datasets as needed
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