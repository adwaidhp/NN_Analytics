README Update: XNOR Training Improvements
Overview

This project was updated to stabilize training and improve numerical behavior of the existing neural network implementation.
The original code was prone to NaN values during training due to high learning rates and weight initialization issues.
We implemented a more stable training loop, better weight initialization, safer math operations, and cleaner logging.

✨ Key Changes Made
1. Weight Initialization

Replaced fixed weight values (1.0) with small random weights between -0.05 and 0.05.

Randomized initialization improves training stability and prevents early divergence.

Implemented in model.h using:

double rand_weight(double scale = 0.05);

2. Learning Rate Adjustment

Reduced learning rate from 0.05 to 0.0001.

This prevents large gradient updates that caused NaN values in the forward/backward pass.

3. Tanh Activation & Derivative Fix

Renamed ACT_FUN::tanh to ACT_FUN::tanh_act to avoid name conflicts with the standard library.

Corrected derivative implementation:

derivative of tanh(x) = 1 - tanh(x)^2


Implemented in derivative.h.

4. Network Architecture

Defined a 3–4–1 architecture for 3-input XNOR:

Input layer: 3 neurons

Hidden layer: 4 neurons

Output layer: 1 neuron

Used tanh_act for all neurons to keep outputs in a bounded range.

All connections created programmatically instead of hardcoded, for flexibility.

5. NaN Detection & Safe Training

Added NaN/inf guard during training:

if (std::isnan(output) || std::isinf(output)) stop training;


Prevents silent corruption of weights when instability occurs.

Training exits with a clear error message.

6. Training Loop Improvements

Reduced training epochs to 250 by default for faster experiments.

Limited logging using:

int print_every = 10;


to avoid overwhelming the console output.

Logs include:

Input values

Label values

Network outputs

Error values

Status of training step

7. Cleaner Code Interface

Removed rvalue initializer errors by properly constructing ip_to_nn, nn_to_nn, and nn_to_op objects before adding them to the network.

Updated unit_test.cpp to provide a clean, structured training log.

🧪 Example Log Output
Epoch: 20 Sample: 3
Input: [0 1 1]
label: [1]
Output: [0.862347]
Error: [-0.137653]
Training successful