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
    {{2, 4, 3}, {7, 13, 10}},//y=3x+1
    {{5, 10, 15}, {6, 11, 16}},//y=x-1
    {{2, 3, 4}, {5, 7, 9}},//y=2x+1

};

    double delta = 0.01; // Threshold for the error
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