#include <chrono>
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
    {{1, 2, 3}, {28, 38, 48}},   // 10*1+18=28, 10*2+18=38, 10*3+18=48
    {{0, 4, 5}, {18, 58, 68}},   // 10*0+18=18, 10*4+18=58, 10*5+18=68
    {{6, 7, 8}, {78, 88, 98}},   // 10*6+18=78, 10*7+18=88, 10*8+18=98
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