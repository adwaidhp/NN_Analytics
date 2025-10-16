Quantum Resonant Neural Network

A neural network with a Resonant Activation Function that helps capture complex patterns in data.

Features

Custom Resonant Activation: f(x) = exp(-0.5*x^2) * sin(5*x)

Flexible network architecture (inputs, hidden neurons, outputs)

Forward and backward propagation

Detailed training logs showing input, output, label, and error

Quick Start

Compile the code:
g++ -o working_demo.exe working_demo.cpp
g++ -o test_real_data.exe test_real_data.cpp

Run the demos:
.\working_demo.exe
.\test_real_data.exe

Example Output
Input: [4.0 25.0 16.0]
Label: [2.0 5.0 4.0]
Output: [1.991425 4.902081 3.931862]
Error: [0.008575 0.097919 0.068138]
Training successful

Code Files

network.h → Core network and training logic

model.h → Defines model architecture

resonant_activation.h → Resonant activation function

working_demo.cpp → Demo with sample data

test_real_data.cpp → Demo with real data

How It Works

Inputs go into the network

Hidden neurons transform them using resonant activation

Output neurons predict the target

Network trains using backpropagation