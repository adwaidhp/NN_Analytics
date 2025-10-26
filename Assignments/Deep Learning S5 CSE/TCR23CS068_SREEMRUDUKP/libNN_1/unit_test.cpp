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
    {{0.1, 0.5, 0.8}, {0.3, 0.6, 0.9}},  
    {{0.0, 0.2, 0.4}, {0.1, 0.3, 0.5}},  
    {{0.7, 0.8, 0.9}, {0.5, 0.55, 0.6}}, //y=x/2 + .15
    {{0.3, 0.6, 0.9}, {0.25, 0.5, 0.75}}
        // Add more datasets as needed
    };

    double delta = 0.005; // Threshold for the error decreased since the data set contains values only in range -1 to 1
    training obj = training();

    // Iterate over each dataset and train the model
    for(int i=0;i<75;i++){    //epochs
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