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
        {{4, 10, 16}, {22, 28, 34}},
        {{1, 2, 3}, {6, 8, 10}},
        {{5, 7, 9}, {15, 21, 27}}
    };

    // Dynamically adding one more dataset
    datasets.emplace_back(Dataset{{2, 4, 6}, {8, 12, 16}});

    double delta = 0.1; // Threshold for the error
    training obj = training();

    // Start overall training timer
    auto start_time = std::chrono::high_resolution_clock::now();

    // Training loop
    for (int epoch = 0; epoch < 60; epoch++) // epochs
    {
        std::cout << "\n========== Epoch " << epoch + 1 << " ==========\n";

        for (auto &dataset : datasets)
        {
            bool result = obj.train(mdl._nn, dataset.input, dataset.label, delta);

            if (result)
            {
                std::cout << "Dataset trained successfully.\n";
            }
            else
            {
                std::cout << "Retry training with adjusted parameters.\n";
            }
        }

        std::cout << "Completed Epoch: " << epoch + 1 << std::endl;
    }

    // End overall training timer
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> total_duration = end_time - start_time;
    std::cout << "\nTotal Training Time: " << total_duration.count() << " seconds\n";

    return 0;
}
