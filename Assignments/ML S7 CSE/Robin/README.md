# Neural Network for Linear Regression: y = 2x + 1

## Overview
This project implements a custom neural network framework in C++ designed to learn simple linear regression relationships. The specific model is trained to approximate the function `y = 2x + 1` using a single-neuron architecture with backpropagation.

## Project Structure
The implementation consists of multiple header files that together form a complete neural network framework:

### Core Network Components
- **`network.h`** - Main neural network class managing layers and connections
- **`neuron.h`** - Individual neuron implementation with forward/backward propagation
- **`model.h`** - Pre-configured model setup for the linear regression task

### Data Handling
- **`input.h`**, **`label.h`**, **`output.h`**, **`error.h`** - Data container classes
- **`data_set.h`** - Random data generator for training
- **`training.h`** - Training logic and convergence checking

### Mathematical Functions
- **`activation.h`** - Activation functions (sigmoid, ReLU, tanh, leaky ReLU, linear)
- **`derivative.h`** - Derivatives for backpropagation
- **`global_enum.h`** - Activation function enumerations

### Supporting Files
- **`structures.h`** - Data structures for network connections
- **`unit_test.cpp`** - Main training program
- **`test.cpp`** - Data generation testing
- **`run_many_times.sh`** - Bash script for multiple training iterations

## Key Changes Made to Original Files

### Critical Fixes Applied:
1. **`global_enum.h`**: Renamed `tanh` to `tanh_act` to avoid naming conflicts with standard library function
2. **`network.h`**: Added explicit template arguments to `std::pair` calls (`std::pair<bool, double>`) for C++11 compatibility
3. **`activation.h` & `derivative.h`**: Updated switch cases to use `tanh_act` and implemented proper mathematical functions

### Model-Specific Modifications for y = 2x + 1:

#### `model.h`
- Simplified architecture to single neuron with linear activation
- Initialized bias to 0.0
- Set learning rate to 0.01 for optimal convergence
- Configured single input-to-neuron connection with trainable weight

#### `unit_test.cpp`
- Updated test cases for `y = 2x + 1` function:
  - `{0.0, 1.0}` (2×0 + 1 = 1)
  - `{1.0, 3.0}` (2×1 + 1 = 3)
  - `{2.0, 5.0}` (2×2 + 1 = 5)
  - Additional validation cases

#### `training.h`
- Enhanced training algorithm with progress monitoring
- Added convergence checking with configurable tolerance (delta = 0.1)
- Implemented step-by-step output for training visualization

#### `neuron.h`
- Improved backpropagation with proper gradient calculation
- Fixed weight update logic for linear regression
- Added bias adjustment during training

## Model Architecture