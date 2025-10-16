#include <iostream>
#include <vector>
#include <iomanip>
#include "model.h"
#include "training.h"
using namespace std;

int main() {
    vector<vector<double>> inputs = {
        {1, 2, 3},
        {2, 4, 6},
        {3, 6, 9},
        {4, 8, 12},
        {5, 10, 15}
    };

    Training trainer(0.001, 0.001);
    Model model(3); // 3 input features

    cout << fixed << setprecision(6);

    for (auto &input : inputs) {
        Dataset data;
        data.input = input;

        // Label = sum of all inputs
        double sum = 0;
        for (double v : input) sum += v;
        data.label = {sum};

        bool trained = false;
        int epoch = 0;

        while (!trained && epoch < 1000) {
            trained = trainer.train(model, data);
            epoch++;
        }
    }

    return 0;
}
