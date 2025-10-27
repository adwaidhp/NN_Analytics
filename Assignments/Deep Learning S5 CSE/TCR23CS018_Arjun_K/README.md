C++ Neural Network Project

This project is a simple feedforward neural network built from scratch in C++.

Project Goal

The final goal of this network is to approximate the following linear function:
f(a, b, c) -> (out_1, out_2, out_3)

Where:

out_1 = a + 1

out_2 = 2*b + 2

$out_3 = 3*c + 3

The network architecture is a 3-layer, fully-connected model (3 input neurons, 3 hidden neurons, 3 output neurons). The training data and main execution are handled in unit_test.cpp.

Summary of Changes (Original vs. Final)

The original code files had several critical bugs that prevented the network from learning at all. The following is a summary of all changes made to fix the project.

1. Core Backpropagation Bug (in neuron.h):

Original: The backward function was mathematically incorrect. It did not properly calculate the node's error (delta) and attempted to update outgoing weights in a flawed way.

Final: The backward function was completely rewritten to correctly implement backpropagation. The new logic now:

Calculates the node's delta (error term) based on the error from the next layer.

Uses this delta to update the node's own bias.

Uses this delta to correctly update all incoming weights (e.g., w_ki).


2. Activation Function Bugs (in activation.h):

Original: The leaky_relu function was implemented as return x;, making it a simple linear function (the same as sigmoid and tanh in the original file).

Final: leaky_relu is now correctly implemented as:

if (x > 0.0) { return x; }
return (0.01 * x);


3. Derivative Bugs (in derivative.h):

Original: The derivative for leaky_relu was implemented as return (0.01 * x);.

Final: The derivative is now correctly implemented as the constant 0.01 for negative inputs:

if (x > 0.0) { return 1.0; }
return 0.01;


4. Model Training Configuration (in model.h):

Original: The input-layer weights (ip_to_nn) were set to trainable: false and had incorrect weights (-1.0).

Final: The input-layer weights are all set to trainable: true with a default weight of 1.0, allowing the network to actually learn from the inputs. The learning rate was also tuned to 0.000001 (1e-6) for stable convergence on the linear problem.


5. Training Data (in unit_test.cpp):

Original: The datasets list contained data for an unknown linear function. The loop ran for only 60 epochs.

Final: The datasets list now contains correct data for the target function $f(a+1, 2b+2, 3c+3)$. The epoch count was increased to 1000 to give the network time to learn, and the delta (error threshold) was set to 0.1 for a precise answer.