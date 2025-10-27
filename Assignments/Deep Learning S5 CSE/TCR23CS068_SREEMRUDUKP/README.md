Changes Made:
model.h:
    Added Hidden Layer 2
    Updated node_list
    Updated nn_to_nn connections
    Changed activation function
    Input/hidden to ReLU
    Output to Sigmoid
    Weights allowed to update (true)
    Adjusted weights to differnt values 
    increased learning rate

unit_test.cpp / dataset setup:
    Normalized inputs/output dataset values to [0,1]
    Adjusted number of iterations and delta
    Decreased threshold for error


Detailed Description:

1. Network Structure and Layers:

    Initially, the network had 3 layers:
        Input Layer (3 neurons)
        Hidden Layer 1 (3 neurons)
        Output Layer (3 neurons)
    I added a second hidden layer to make the network deeper:
    New network structure:
        Input Layer (3 neurons)
        Hidden Layer 1 (3 neurons)
        Hidden Layer 2 (3 neurons) – new
        Output Layer (3 neurons)

    Activation functions:
    ReLU for input and hidden layers to ensures faster learning.
    Sigmoid for output layer to outputs bounded between 0–1, matching normalized dataset values.
    (Tried others also)

2. Dataset

    Inputs and outputs are normalized to [0,1].
    Normalized data to ecplore activations functions effect in boundary condition cases: Sigmoid output matches expected values. Tried other activation functions (Tanh, Leaky ReLU), but results were not as good for bounded output

3. Weights

    Allowed weights to update during training (true) so that the network could learn patterns.
    Changed initial weights and observed changes in speed accuracy etc:
    Input i1 to 1.5, i2 to 1.0, i3 to 0.5

4. Learning rate, threshold error and number of iterations

    Learning rate: 0.0001 for faster learning.
    Threshold error (delta): reduced from 0.1 to 0.005 since we have normalized output so it should be more accurate.
    Number of iterations/epochs: increased for better convergence.

5. Connection Strategy
    Updated input of output node from layer 2 to 3

