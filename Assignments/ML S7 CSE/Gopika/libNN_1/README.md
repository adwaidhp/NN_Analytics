Project Title: Sequence Doubling using Feedforward Neural Network
Description:

This project implements a simple feedforward neural network that learns the relationship between input and output number sequences, specifically the pattern y = 2x.
The aim was to train the model to correctly predict doubled values for unseen inputs by learning through examples instead of hardcoding the rule.

Changes Made in Files:

network.cpp / network.h

Adjusted the network structure to include one hidden layer with 4 neurons for better non-linear learning capacity.

Changed learning rate from 0.5 to 0.1 for smoother convergence.

Modified weight initialization to smaller random values in the range [-0.5, 0.5] to prevent saturation.

Implemented improved forward and backward propagation for continuous value prediction.

train.cpp

Updated training data generation to follow the rule output = 2 * input.

Added normalization of input and output values to improve network stability.

Increased number of epochs to 800 for better learning accuracy.

Included tracking of training error per iteration.

test.cpp

Modified to evaluate model performance on unseen input data.

Displays both predicted and actual outputs for comparison.

Neural Network Structure:

Input Layer: 1 neuron (sequence input)

Hidden Layer: 4 neurons, activation = Sigmoid

Output Layer: 1 neuron, activation = Linear

Learning Rate: 0.1

Epochs: 800

Results:

Model successfully learned the doubling pattern (y = 2x) with minimal error after training.

Predictions for test inputs were very close to expected outputs.

Reducing the learning rate improved convergence smoothness and reduced oscillations.

Conclusion:

The neural network effectively captured the y = 2x pattern through supervised learning.
Tuning parameters such as the learning rate, weight initialization, and hidden neurons significantly enhanced performance and stability.