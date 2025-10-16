#include "model.h"
#include <iomanip>
using namespace std;

int main() {
    Dataset data;
    data.generate(5, 1.0); // x = 0,1,2,3,4

    Model model(3); // 3 weights
    cout << fixed << setprecision(6);

    // simulate 10 training steps
    for (int step = 0; step < 10; step++) {
        vector<double> output = model.predict(data.input);
        vector<double> error = model.compute_error(output, data.label);

        // print current step
        cout << "Step " << step+1 << ":\n";
        cout << "Input: [";
        for (double v : data.input) cout << v << " ";
        cout << "]\nLabel: [";
        for (double v : data.label) cout << v << " ";
        cout << "]\nOutput: [";
        for (double v : output) cout << v << " ";
        cout << "]\nError: [";
        for (double v : error) cout << v << " ";
        cout << "]\n\n";

        // update weights
        model.update_weights(data.input, error, 0.05);
    }

    return 0;
}
