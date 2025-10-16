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
	{{3, 2, 4}, {1.09, 0.69, 1.38}}, // y = log(x)
    	{{7, 12, 13}, {1.91, 2.28, 2.35}},    // cube root fn
    	{{1, 2, 3}, {1, 16, 81}} // x^4 
        // Dataset values changed 
    };

    double delta = 0.1; // Threshold for the error changed to 0.1
    training obj = training();

    // Iterate over each dataset and train the model
    for(int i=0;i<55;i++){    //epoch value changed to 55
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
