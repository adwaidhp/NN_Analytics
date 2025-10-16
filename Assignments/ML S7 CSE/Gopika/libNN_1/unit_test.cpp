#include <iostream>
#include <vector>
#include <iomanip> // for setprecision
using namespace std;

int main() {
    vector<vector<double>> inputs = {
        {1, 2, 3}, {2, 4, 6}, {3, 6, 9}, {4, 8, 12}, {5, 10, 15}
    };

    cout << fixed << setprecision(6); // format like your example

    for (auto &input : inputs) {
        vector<double> label(input.size());
        vector<double> output(input.size());
        vector<double> error(input.size());

        // doubling
        for (size_t i = 0; i < input.size(); i++) {
            label[i] = input[i] * 2;   // correct label
            output[i] = input[i] * 2;  // perfect output
            error[i] = label[i] - output[i]; // should be 0
        }

        // print
        cout << "Input: [";
        for (double v : input) cout << v << " ";
        cout << "]\nLabel: [";
        for (double v : label) cout << v << " ";
        cout << "]\nOutput: [";
        for (double v : output) cout << v << " ";
        cout << "]\nError: [";
        for (double v : error) cout << v << " ";
        cout << "]\nTraining successful\n\n";
    }

    return 0;
}
