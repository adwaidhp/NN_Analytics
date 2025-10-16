# Neural Network Project - ML S7 CSE

## ⚙️ Configuration / Updates

The following changes have been made to the network configuration:

- **Dataset values**: Updated dataset values are being used for training.
- **Input**:  `(x1, x2, x3)`
- **Output**: `(x1 * x2 * x3, 2*(x1 + x2 + x3), 3*(x1 + x2 + x3))` 
- **Network architecture**:
  - Layer 0: 3 neurons (Input Layer:leaky_relu)
  - Layer 1: 3 neurons (Hidden Layer:sigmoid)
  - Layer 2: 3 neurons (Output Layer:leaky_relu)
- **Weights**: All 1.0
- **Epochs**: 10 (can be increased)
- **Learning rate**: 0.001
- **Error threshold**: 0.001

