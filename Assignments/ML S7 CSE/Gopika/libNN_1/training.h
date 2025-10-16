#ifndef TRAINING_H
#define TRAINING_H

#include "model.h"

class Training {
public:
    double learning_rate;
    double threshold;

    Training(double lr = 0.01, double th = 0.01) {
        learning_rate = lr;
        threshold = th;
    }

    bool train(Model &model, Dataset &data) {
    vector<double> output = model.predict(data.input);
    vector<double> error = model.compute_error(output, data.label);
    model.update_weights(data.input, error, learning_rate);

    bool success = true;
    for (double e : error)
        if (fabs(e) > threshold)
            success = false;

    // print results
    cout << "Input: [";
    for (double v : data.input) cout << v << " ";
    cout << "]\nLabel: [";
    for (double v : data.label) cout << v << " ";
    cout << "]\nOutput: [";
    for (double v : output) cout << v << " ";
    cout << "]\nError: [";
    for (double v : error) cout << v << " ";
    cout << "]\n";

    if (success)
        cout << "Training successful\n\n";
    else
        cout << "Try again\n\n";

    return success;
}

};

#endif
