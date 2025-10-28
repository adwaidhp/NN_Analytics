#include <chrono>
#include <unistd.h>
#include <list>
#include <random>
#include <iostream>
#include <algorithm>

#include "data_set.h"
#include "training.h"
#include "model.h"

// Define a structure to hold input and label lists
struct Dataset
{
    std::list<double> input;
    std::list<double> label;
};

// Helper to normalize values to [0, 1]
double normalize(double x, double min, double max)
{
    return (x - min) / (max - min);
}

int main()
{
    data_set dts = data_set();
    model mdl = model();
    mdl.set();
    mdl._nn.set_learning_rate(0.001);
    // double delta = 0.01;

    // Better dataset: y = 3x + 2 + noise (normalized)
    std::default_random_engine gen(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<double> dist(0.0, 10.0);
    std::normal_distribution<double> noise(0.0, 0.3);

    std::list<Dataset> datasets;
    for (int i = 0; i < 50; ++i)
    {
        Dataset ds;
        for (int j = 0; j < 3; ++j)
        {
            double x = dist(gen);
            double y = 3 * x + 2 + noise(gen); // Linear pattern with small randomness

            // Normalize to [0, 1]
            ds.input.push_back(normalize(x, 0.0, 10.0));
            ds.label.push_back(normalize(y, 2.0, 32.0));
        }
        datasets.push_back(ds);
    }

    double delta = 0.05; // Threshold for acceptable error
    training obj = training();

    // Train for 60 epochs
    for (int i = 0; i < 60; i++)
    {
        int success_count = 0;

        // Shuffle datasets each epoch for better generalization
        std::vector<std::reference_wrapper<Dataset>> shuffled(datasets.begin(), datasets.end());
        std::shuffle(shuffled.begin(), shuffled.end(), gen);

        for (auto &ds : shuffled)
        {
            bool result = obj.train(mdl._nn, ds.get().input, ds.get().label, delta);

            if (result)
                success_count++;
        }

        std::cout << "Epoch " << i + 1 << " completed. Successful trainings: "
                  << success_count << "/" << datasets.size() << std::endl;

        usleep(30000); // Slight pause for readability
    }

    std::cout << "Training complete!" << std::endl;
    return 0;
}
