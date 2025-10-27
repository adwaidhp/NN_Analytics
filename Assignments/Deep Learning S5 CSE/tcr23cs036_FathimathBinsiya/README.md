# Neural Network Model — Custom Implementation

## Overview
This project implements a simple feedforward neural network built from scratch in C++ as part of the **Deep Learning S5 CSE** coursework.  
The network is trained using custom datasets to approximate nonlinear functions such as **exponential** and **logarithmic** mappings.


## Work Done

- Fixed **tanh**, **Sigmoid**, **ReLU**, and **Leaky ReLU** implementations in `derivative.h` and `activation.h` (replaced placeholder functions).
- Fixed error in `global_enum.h` (resolved name conflict issues with the `cmath` module).
- Updated dataset to test **exponential (y = 2^x)** and **logarithmic (y = log(x))** relationships.
- Increased total number of layers to **4 (2 hidden layers)**.
- Modified `unit_test.cpp` to iterate through multiple datasets and train over 60 epochs.
- Added assertion-safe dataset configuration and improved model initialization.


###  Network Architecture

| Layer | Description     | Activation Function | No. of Neurons |
| 1     | Input Layer     | `tanh`              | 3 |
| 2     | Hidden Layer 1  | `sigmoid`           | 3 |
| 3     | Hidden Layer 2  | `relu`              | 3 |
| 4     | Output Layer    | `leaky_relu`        | 3 |


### Training Configuration

- **Dataset values**:  
  Used exponential (`y = 2^x`) and logarithmic (`y = log(x)`) datasets:
  ```cpp
  {{0, 1, 2}, {1, 2, 4}},
  {{4, 5, 6}, {16, 32, 64}},
  {{1, 2, 3}, {0, 0.693, 1.098}},
  {{5, 6, 7}, {1.609, 1.792, 1.946}},
  ```

- **Epochs**: 60  
- **Error threshold (delta)**: `0.1`  
- **Learning rate**: `0.00001`  
- **Weight initialization**: Randomized within `[-1, 1]`  
- **Training strategy**: Iterative training over multiple datasets until error < delta  


##  Key Learnings

- Understood custom implementation of **activation functions** and their derivatives.
- Gained experience in **multi-layer feedforward network setup**.
- Improved debugging skills for C++ neural network structures and assertions.
- Learned how to handle **non-linear datasets** (exponential/logarithmic).

##  Execution Steps

###  Using WSL 
```bash
# Compile
g++ unit_test.cpp -o output

# Run
./output
```



##  Author
**TCR23CS036 — Fathimath Binsiya**  
Deep Learning S5 CSE, NN Analytics Assignment

