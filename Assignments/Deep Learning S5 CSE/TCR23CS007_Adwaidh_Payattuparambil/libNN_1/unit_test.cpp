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
        //linear
        {{1, 2, 3}, {2, 4, 6}},
        {{2, 4, 6}, {5, 9, 13}}, //y=2x+1
        //quadratic
        {{1, 2, 3}, {1, 4, 9}}, 
        {{3, 5, 7}, {10, 26, 50}},//y=(x^2)+1
        
        // Add more datasets as needed
    };


    double delta = 0.1; // Threshold for the error
    training obj = training();
    std::cout << "Modified training model" << std::endl;

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