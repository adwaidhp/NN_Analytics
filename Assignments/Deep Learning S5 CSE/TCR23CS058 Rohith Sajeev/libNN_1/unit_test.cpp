#include <chrono>
#include <unistd.h>
#include <list>
#include <iostream>
#include <cstdio>

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
    // Redirect stdout to file (captures both cout and printf)
    FILE* logfile = freopen("1.log", "w", stdout);
    
    if (logfile == NULL)
    {
        std::cerr << "Error: Could not open 1.log file" << std::endl;
        return 1;
    }
    
    data_set dts = data_set();
    model mdl = model();
    mdl.set();

    // Create a list of datasets for f(x) = x^2 + 3
    std::list<Dataset> datasets = {
        {{1, 2, 3}, {4, 7, 12}},
        {{2, 3, 4}, {7, 12, 19}},
        {{3, 4, 5}, {12, 19, 28}},
        {{4, 5, 6}, {19, 28, 39}},
        {{5, 6, 7}, {28, 39, 52}}
        // Add more datasets as needed
    };

    double delta = 0.1; // Threshold for the error
    training obj = training();

    // Iterate over each dataset and train the model
    for(int i=0;i<50;i++){    //epochs
        for (auto &dataset : datasets)
        {
            bool result = obj.train(mdl._nn, dataset.input, dataset.label, delta);

            if (result)
            {
                printf("Training successful\n");
            }
            else
            {
                printf("Try again\n");
            }
            fflush(stdout);
        }
        printf("in iteration: %d\n", i);
        fflush(stdout);
    }

    fclose(stdout);

    return 0;
}