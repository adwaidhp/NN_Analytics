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
	{{3, 2, 4}, {20.0855, 7.3891, 54.5981}}, // y = e^x
    	{{1, 3, 5}, {2.1, 6.7, 10.3}},    // slightly noisy linear fn
    	{{5, 7, 9}, {1.609, 1.946, 2.197}} // log fn
        // Dataset values changed 
    };

    double delta = 0.1; // Threshold for the error changed to 0.2
    training obj = training();

    // Iterate over each dataset and train the model
    for(int i=0;i<50;i++){    //epoch value changed to 50
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
