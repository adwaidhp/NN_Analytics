# Sequence Summation using Feedforward Neural Network

## Description

This project implements a simple feedforward neural network that learns to compute the **sum of a sequence of numbers**.  
Instead of hardcoding the rule, the network is trained on example sequences and their corresponding sums, allowing it to generalize to unseen inputs.

## Changes Made in Files

### network.h / neuron.h

- Adjusted the network structure to include **one hidden layer** with 4 neurons for improved non-linear learning capacity.
- Hidden layer uses **Sigmoid activation**, output layer uses **Linear activation**.
- Improved forward and backward propagation for accurate sum prediction.
- Initialized weights with small random values in the range [-0.5, 0.5] to prevent saturation.

### training.h

- Increased **learning rate** to 0.1 for faster yet stable convergence.
- Set the number of epochs to **800** for better accuracy.
- Added per-iteration tracking of **training error** to monitor convergence.

### unit_test.cpp

- Updated to evaluate the network's ability to compute **sum of input sequences**.
- Displays input, expected sum (label), predicted output, and error for comparison.

## Neural Network Structure

- **Input Layer:** 3 neurons (sequence input)
- **Hidden Layer:** 4 neurons, activation = Sigmoid
- **Output Layer:** 1 neuron, activation = Linear
- **Learning Rate:** 0.1
- **Epochs:** 800

## Results

- Model successfully learned to compute the sum of input sequences.
- Predictions for test inputs are **very close to actual sums**.
- Increasing the number of hidden neurons and tuning the learning rate improved **accuracy and convergence stability**.

## Conclusion

The neural network effectively captured the summation pattern through supervised learning.  
Careful tuning of hyperparameters such as the learning rate, hidden layer size, and weight initialization significantly enhanced performance and reduced training error.
