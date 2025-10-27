# Custom Neural Network – Multi-Layer Leaky ReLU Implementation

## Work Done

- Implemented a **4-layer neural network** with 2 hidden layers, each containing 3 neurons.
- Fixed **activation function implementations** (`tanh`, `Sigmoid`, `ReLU`, `Leaky ReLU`) in `activation.h` and `derivative.h`.
- Resolved **name conflicts in `global_enum.h`** with the `cmath` module.
- Updated **dataset** to test both **linear** and **quadratic equations**.
- Implemented **custom weight initialization** for all layers.
- Configured **forward and backward propagation** with correct gradient calculation.
- Set up **input-to-layer, layer-to-layer, and layer-to-output connections** for fully connected network structure.
- Trained network with **manual learning rate and error threshold control**.

## Work Done

The following network configuration is used:

- **Number of layers**: 4 (2 hidden layers)
- **Neurons per layer**: 3
- **Activation functions**:
  - Layer 1: `Leaky ReLU`
  - Layer 2: `Leaky ReLU`
  - Layer 3: `Leaky ReLU`
  - Layer 4: `Leaky ReLU`
- **Initial weights**: Custom initialization
- **Learning rate**: 0.00001
- **Error threshold**: 0.1
- **Dataset**: Linear and quadratic equations for testing

## How It Works

- **Forward propagation**: Computes activations for all layers using Leaky ReLU.
- **Backward propagation**: Calculates gradients using the derivative of Leaky ReLU.
- **Training process**: Updates weights using gradient descent until the error threshold is reached.
- **Dataset support**: Works with both linear and quadratic input-output mappings.

## Future Improvements

- Extend support for **different activation functions per layer**.
- Add **adaptive learning rate** for faster convergence.
- Increase **network depth and neurons per layer** for more complex tasks.
- Implement **visualization tools** for training progress, loss curves, and prediction accuracy.
- Extend to **classification tasks** using softmax or other output activations.
