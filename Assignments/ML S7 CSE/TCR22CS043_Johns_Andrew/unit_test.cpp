#include <chrono>
#include <unistd.h>
#include <list>
#include <iostream>
#include <cmath>
#include <limits>

#include "data_set.h"
#include "training.h"
#include "model.h"

// Structure to hold dataset
struct Dataset
{
    std::list<double> input;
    std::list<double> label;
};

bool isnan_safe(double x) {
    return std::isnan(x) || std::isinf(x);
}

int main()
{
    data_set dts = data_set();
    model mdl = model();
    mdl.set();

    training trainer;

    // ✅ XNOR truth table for 3 inputs
    std::list<Dataset> datasets = {
        {{0, 0, 0}, {1}},
        {{0, 0, 1}, {0}},
        {{0, 1, 0}, {0}},
        {{0, 1, 1}, {1}},
        {{1, 0, 0}, {0}},
        {{1, 0, 1}, {1}},
        {{1, 1, 0}, {1}},
        {{1, 1, 1}, {0}}
    };

    double delta = 0.1;
    int epochs = 250;          // ✅ increased total epochs
    int print_every = 10;      // print logs less frequently

    for (int epoch = 0; epoch < epochs; ++epoch)
    {
        int idx = 0;
        for (auto &dataset : datasets)
        {
            bool result = trainer.train(mdl._nn, dataset.input, dataset.label, delta);

            // only print every Nth epoch
            if (epoch % print_every == 0)
            {
                std::cout << "Epoch: " << epoch << " Sample: " << idx << std::endl;

                // Input
                std::cout << "Input: [";
                for (auto it = dataset.input.begin(); it != dataset.input.end(); ++it)
                {
                    std::cout << *it;
                    if (std::next(it) != dataset.input.end()) std::cout << " ";
                }
                std::cout << "]" << std::endl;

                // Label
                std::cout << "label: [";
                for (auto it = dataset.label.begin(); it != dataset.label.end(); ++it)
                {
                    std::cout << *it;
                    if (std::next(it) != dataset.label.end()) std::cout << " ";
                }
                std::cout << "]" << std::endl;

                // Forward pass
                auto output = mdl._nn.run(dataset.input);

                // NaN check
                bool bad = false;
                for (auto v : output)
                    if (isnan_safe(v)) bad = true;

                if (bad) {
                    std::cerr << "❌ NaN detected in output at epoch " << epoch << ", sample " << idx << std::endl;
                    return 1;
                }

                // Output
                std::cout << "Output: [";
                for (auto oit = output.begin(); oit != output.end(); ++oit)
                {
                    std::cout << *oit;
                    if (std::next(oit) != output.end()) std::cout << " ";
                }
                std::cout << "]" << std::endl;

                // Error
                std::cout << "Error: [";
                auto lit = dataset.label.begin();
                for (auto oit = output.begin(); oit != output.end(); ++oit, ++lit)
                {
                    double err = *oit - *lit;
                    std::cout << err;
                    if (std::next(oit) != output.end()) std::cout << " ";
                }
                std::cout << "]" << std::endl;

                std::cout << (result ? "Training successful" : "Try again") << std::endl;
            }

            ++idx;
        }
    }

    std::cout << "\n✅ Training completed successfully.\n";
    return 0;
}
