Neural Network Implementation

Work Done

Implemented a 3-layer neural network (Input → Hidden → Output).

Added ReLU, Leaky ReLU, and Sigmoid activation functions.

Updated dataset values and increased training epochs for better accuracy.

Tuned learning rate and error threshold for smoother convergence.

Ensured proper connections between all layers and stable weight initialization.

Configuration

Layers: 3 (1 hidden layer, 3 neurons each)

Activation functions:
Layer 1 – ReLU
Layer 2 – Leaky ReLU
Layer 3 – Sigmoid

Learning rate: 0.001

Error threshold (delta): 0.05

Epochs: 80

Dataset pattern: Linear relationship between inputs and outputs
{{2,4,6}->{7,11,15}}, {{1,3,5}->{5,9,13}}, {{7,9,11}->{17,21,25}}

Files Modified

model.h: Redesigned 3-layer structure, set activation and weights

unit_test.cpp: Added new dataset, increased epochs, lowered delta

data_set.h, training.h, network.h: Used as provided

Results

Model trained successfully with linear data.

ReLU and Leaky ReLU improved learning speed.

Reduced delta led to faster, more stable convergence.

Summary
A compact neural network model with tuned parameters was implemented to demonstrate forward and backward propagation in C++. The setup efficiently trains on small datasets and showcases basic deep learning principles.
