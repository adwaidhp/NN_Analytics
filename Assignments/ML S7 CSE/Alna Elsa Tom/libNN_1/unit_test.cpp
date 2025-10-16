#include <chrono>
#include <list>
#include <iostream>

#include "data_set.h"
#include "training.h"
#include "model.h"

struct Dataset {
    std::list<double> input;
    std::list<double> label;
};

int main()
{
    data_set dts;
    model mdl;
    mdl.set();

    training trainer;
    double delta = 0.001;  // smaller threshold for precise learning

    // Create a simple linear dataset
    std::list<Dataset> datasets;

    for (int i = 1; i <= 10; i++) {
        Dataset ds;
        double x1 = i;
        double x2 = i + 1;
        double x3 = i + 2;

        ds.input = {x1, x2, x3};
        ds.label = {x1 * x2 * x3, 2*(x1 + x2 + x3), 3*(x1 + x2 + x3)};

        datasets.push_back(ds);
    }

    // Train the model for several epochs
    for(int epoch = 0; epoch < 10; epoch++) { // increase epochs if needed
        for(auto &dataset : datasets) {
            bool result = trainer.train(mdl._nn, dataset.input, dataset.label, delta);

            std::cout << (result ? "Training successful" : "Try again") << " | "
                      << "Inputs: ";
            for(auto v : dataset.input) std::cout << v << " ";
            std::cout << "| Labels: ";
            for(auto v : dataset.label) std::cout << v << " ";
            std::cout << std::endl;
        }
        std::cout << "Epoch " << epoch << " completed\n";
    }

return 0;
}