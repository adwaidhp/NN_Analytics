#include <chrono>
#include <unistd.h>
#include <list>
#include <iostream>
// 

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
    // std::list<Dataset> datasets = {
    //     {{4, 10, 16}, {22, 28, 34}},
    //     {{1, 2, 3}, {6, 8, 10}},
    //     {{5, 7, 9}, {15, 21, 27}}
    //     // Add more datasets as needed
    // };

    std::list<Dataset> datasets = {
                x1          x2
            {{-1.0472, -0.7854, -0.5236}, 
                y1      y2
            {2.0000, 1.4142, 1.1547}},
            {{0.0, 0.5236, 0.7854},
            {1.0000, 1.1547, 1.4142}},
            {
                {-1.3090, -1.0472, -0.7854},       // x values
                {3.0000, 2.0000, 1.4142}           // sec(x)
            }
        
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