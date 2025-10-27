Deep Learning S5 CSE: Multi-Output Network Training Report

1. Project Goal

The primary objective was to train a multi-layer neural network to simultaneously learn three distinct, multi-variable linear functions from the same input data, achieving a low error threshold (convergence criteria implied by "Training successful").

2. Dataset and Target Functions

The model was trained on three independent functions based on the input vector $\mathbf{x} = [x_1, x_2, x_3]$:

Output 1: $y_1 = 3x_1 + 1$

Output 2: $y_2 = x_2 - 1$

Output 3: $y_3 = 2x_3 + 1$

(Note: Initial attempts to implement a quadratic function required a deeper model, confirming the non-linearity needed to be addressed by capacity.)

3. Challenges Encountered & Solutions

Issue

Observation / Symptom

Solution

Numerical Instability

Output: [nan nan nan ], followed by "Training successful".

Corrected activation function names (tanh_act) and implemented small initial weight/bias strategies to prevent overflow.

Vanishing Gradient

Using Sigmoid activation caused gradients to vanish, leading to identical output across all epochs and no learning.

Replaced Sigmoid with a combination of ReLU and Leaky ReLU in hidden layers for stable, non-zero gradient flow.

Symmetry

Using the same bias and activation function for every node in a layer resulted in constant, symmetric output.

Used different activation functions and biases within the hidden layer to break symmetry and encourage unique feature learning.

Learning Speed

The original learning rate of $0.00001$ was too slow.

Increased the learning rate (though the exact final value is not shown below, the training speed indicates it was significantly increased from the minimum).

