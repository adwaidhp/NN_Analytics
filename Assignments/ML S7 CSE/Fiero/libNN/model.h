#ifndef __MODEL_H__
#define __MODEL_H__

#include "network.h"
#include "resonant_activation.h" // Ensures our innovative function is included

// An enum to easily choose which model architecture to build
enum class MODEL_TYPE {
    REGRESSION, // The original 4-input, 1-output model for general tasks
    SPIRAL      // The 1-input, 2-output model for the spiral prediction task
};

class model
{
public:
    network _nn = network();

    model() {}

    /**
     * @brief Configures and builds the neural network architecture.
     * @param type The type of model to build (REGRESSION or SPIRAL).
     */
    void set(MODEL_TYPE type)
    {
        std::list<std::list<std::pair<ACT_FUN, double>>> node_list;

        // --- Define the Layer Structure (Common for both models) ---
        // This architecture uses our innovative Resonant Activation Function in the hidden layer.
// --- Define the Layer Structure (Common for both models) ---
if (type == MODEL_TYPE::REGRESSION)
{
    node_list = {
        { {ACT_FUN::leaky_relu, 1.0}, {ACT_FUN::leaky_relu, 1.0}, {ACT_FUN::leaky_relu, 1.0}, {ACT_FUN::leaky_relu, 1.0} }, // 4 input nodes
        {
            {ACT_FUN::resonant_func, 5.0},
            {ACT_FUN::resonant_func, 2.0},
            {ACT_FUN::resonant_func, 4.0}  // Hidden layer
        },
        {
            {ACT_FUN::leaky_relu, 3.0} // Output neuron
        }
    };
}



        _nn.initialize(node_list);
        _nn.set_learning_rate(0.02);
        _nn.in.clear(); // Reset inputs before building

        // --- Configure Inputs and Outputs Based on Model Type ---
        if (type == MODEL_TYPE::REGRESSION)
        {
            std::cout << "🔧 Building REGRESSION model (4 inputs, 1 output)" << std::endl;
            // 4 inputs for the general regression task
            for(int i = 0; i < 4; ++i) _nn.in.push_back(1.0);
            for(int i = 0; i < 4; ++i) {
                ip_to_nn conn = {0, (unsigned int)i, 0, 1.0, false};
                _nn.add(conn);
            }
            // 1 output
            nn_to_op o1 = {2, 0, 0, 1.0, false};
            _nn.add(o1);
        }
        else if (type == MODEL_TYPE::SPIRAL)
        {
            std::cout << "🌀 Building SPIRAL model (1 input, 2 outputs)" << std::endl;
            // 1 input (the angle theta) for the spiral task
            _nn.in.push_back(1.0);
            ip_to_nn i1 = {0, 0, 0, 1.0, false};
            _nn.add(i1);
            // 2 outputs (for the x and y coordinates)
            nn_to_op o1 = {2, 0, 0, 1.0, false};
            nn_to_op o2 = {2, 1, 0, 1.0, false};
            _nn.add(o1);
            _nn.add(o2);
        }

        // --- Define Internal Wiring (Common for both models) ---
        nn_to_nn n0n10 = {0, 0, 0, 1, 0, 0, 1.0, false};
        nn_to_nn n0n11 = {0, 1, 0, 1, 1, 0, 1.0, false};
        nn_to_nn n0n12 = {0, 2, 0, 1, 2, 0, 1.0, false};
        nn_to_nn n10n20 = {1, 0, 0, 2, 0, 0, 1.0, true};
        nn_to_nn n11n20 = {1, 1, 0, 2, 0, 0, 1.0, true};
        nn_to_nn n12n20 = {1, 2, 0, 2, 0, 0, 1.0, true};
        nn_to_nn n10n10 = {1, 0, 0, 1, 0, 0, 1.0, false};
        nn_to_nn n12n11 = {1, 2, 0, 1, 1, 0, -1.0, false};

        _nn.add(n0n10);
        _nn.add(n0n11);
        _nn.add(n0n12);
        _nn.add(n10n20);
        _nn.add(n11n20);
        _nn.add(n12n20);
        _nn.add(n10n10);
        _nn.add(n12n11);
        
        std::cout << "🌟 Model initialized with " << _nn.in.size() << " inputs and " << _nn.out.size() << " outputs" << std::endl;
    }
};

#endif