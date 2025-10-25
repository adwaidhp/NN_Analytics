#include <chrono>
#include <unistd.h>
#include <list>
#include <iostream>

#include "data_set.h"
#include "training.h"
#include "model.h"

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

    std::list<Dataset> datasets = {
        {{4, 10, 16}, {22, 28, 34}},
        {{1, 2, 3}, {6, 8, 10}},
        {{5, 7, 9}, {15, 21, 27}}};

    double delta = 0.1;
    training obj = training();

    for (int i = 0; i < 60; i++)
    {
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