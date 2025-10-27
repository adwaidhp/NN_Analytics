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
        {{2, 4, 6}, {7, 11, 15}},
        {{1, 3, 5}, {5, 9, 13}},
        {{7, 9, 11}, {17, 21, 25}}
    };

    double delta = 0.05; // Stricter error threshold
    training obj = training();

    for (int i = 0; i < 80; i++) // Slightly more epochs
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
